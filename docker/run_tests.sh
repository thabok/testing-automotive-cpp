docker build . -t btc_embeddedplatform

docker run --rm \
    --volume "$(pwd)/..:/workdir \
    --workdir "/workdir" \
    btc_embeddedplatform \
    python3 -u tst/run_tests.py
