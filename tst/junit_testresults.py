import json


def dump_testresults_mochajson(file, rbt_response, exec_start_time, exec_end_time, test_cases):
    """Dumps the test results in the mocha-json format."""
    delta = exec_end_time - exec_start_time
    tc_uid_to_name = {tc['uid']: tc['name'] for tc in test_cases}
    report = {
        "stats": {
            "suites": len(rbt_response["testResults"]),
            "tests": sum(suite["totalTests"] for suite in rbt_response["testResults"].values()),
            "passes": sum(suite["passedTests"] for suite in rbt_response["testResults"].values()),
            "pending": sum(suite["skippedTests"] for suite in rbt_response["testResults"].values()),
            "failures": sum(suite["failedTests"] for suite in rbt_response["testResults"].values()),
            "start": exec_start_time.isoformat() + "Z",
            "end": exec_end_time.isoformat() + "Z",
            "duration": delta.total_seconds() * 1000
        },
        "suites": [],
        "tests": [],
        "passes": [],
        "failures": [],
        "pending": []
    }

    for execModeName, em in rbt_response["testResults"].items():
        for result in em["testResults"]:
            tc_name = tc_uid_to_name[result["rbTestCaseUID"]]
            test_case = {
                "title": tc_name,
                "fullTitle": tc_name,
                "file": execModeName, 
                "duration": 0,
                "currentRetry": 0,
                "err": {},
                "state": result["verdictStatus"].lower()
            }

            if result["verdictStatus"] == "PASSED":
                report["passes"].append(test_case)
            elif result["verdictStatus"] == "FAILED":
                test_case["err"] = {
                    "message": result["execResultMessages"][0]["message"] if result["execResultMessages"] else "No error message",
                    #"stack": "Error: " + (result["execResultMessages"][0]["message"] if result["execResultMessages"] else "No error message")
                }
                report["failures"].append(test_case)
            elif result["verdictStatus"] == "NO_VERDICT":
                report["pending"].append(test_case)

            report["tests"].append(test_case)
            
    with open(file, "w") as json_file:
        json.dump(report, json_file, indent=4)