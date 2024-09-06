import os
import sys

from btc_embedded import EPRestApi, util

work_dir = os.path.dirname(sys.argv[0])
epp_file = os.path.join(work_dir, 'InfotainmentSystem.epp')

# BTC EmbeddedPlatform API object
ep = EPRestApi(version='24.3p0')
ep.put('preferences', [{'preferenceName':'PREVIEW_FEATURE_CPP_SUPPORT', 'preferenceValue': True}])
# Load a BTC EmbeddedPlatform profile (*.epp) and update it
ep.get(f"profiles/{epp_file}", message="Loading test project")
ep.put('architectures', message="Parsing code and updating test project")

# Execute requirements-based tests
scopes = ep.get('scopes')
scope_uids = [scope['uid'] for scope in scopes]
toplevel_scope_uid = scope_uids[0]
rbt_exec_payload = {
    'UIDs': scope_uids,
    'data' : {
        'execConfigNames' : [ 'SIL' ]
    }
}
response = ep.post('scopes/test-execution-rbt', rbt_exec_payload, message="Running requirements-based tests")
rbt_coverage = rbt_coverage = ep.get(f"scopes/{toplevel_scope_uid}/coverage-results-rbt")
util.print_rbt_results(response, rbt_coverage)

# Create project report
report = ep.post(f"scopes/{toplevel_scope_uid}/project-report", message="Creating test report")
# export project report to a file called 'report.html'
ep.post(f"reports/{report['uid']}", { 'exportPath': work_dir, 'newName': 'report' })

# Save *.epp
ep.put('profiles', { 'path': epp_file }, message="Saving test project")

print(f'Finished:\n - Report: report.html \n - Test Project: {os.path.basename(epp_file)}')

    