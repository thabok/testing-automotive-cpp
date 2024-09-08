# C++ Testing for Automotive Embedded
Example repo combining C and C++ code for automotive embedded incl. testing (tests with BTC EmbeddedPlatform, linked to requirements from Polarion) and CD/CD (GitHub Actions / Docker).

## Main branch health
- ![CI](https://github.com/thabok/testing-automotive-cpp/actions/workflows/btc-tests.yml/badge.svg?branch=main)
- [Test Report](https://thabok.github.io/testing-automotive-cpp/report.html)

## Relevant files

### Implementation & Test
- Main Class: [InfotainmentSystem.cpp](src/InfotainmentSystem.cpp) (with related CPP classes and C-functions)
- Test project: [InfotainmentSystem.epp](tst/InfotainmentSystem.epp)

### CI/CD
- Automated test workflow: [run_tests.py](tst/run_tests.py)
- Docker: [Dockerfile](docker/Dockerfile)
- Pipeline: [GitHub Actions](.github/workflows/btc-tests.yml)
