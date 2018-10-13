#xmet

Intro for new developers
This is a quick introduction to get new developers up to speed on xmet.

Starting xmet

and then proceed with:

git clone https://github.com/TTcoinDeveloper/xmet
cd xmet
git submodule update --init --recursive
cmake -DCMAKE_BUILD_TYPE=Debug .
make
./programs/witness_node/witness_node




This will launch the witness node.

If you would like to launch the command-line wallet,
you must first specify a port for communication with the witness node. To do this,
add text to witness_node_data_dir/config.ini as follows, then restart the node:

rpc-endpoint = 127.0.0.1:8090

Then, in a separate terminal window, start the command-line wallet cli_wallet:

./programs/cli_wallet/cli_wallet
To set your iniital password to 'password' use:

>>> set_password password
>>> unlock password
To import your initial balance:

>>> import_balance nathan [5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3] true
If you send private keys over this connection, rpc-endpoint should be bound to localhost for security.

A list of CLI wallet commands is available here.

Code coverage testing
Check how much code is covered by unit tests, using gcov/lcov (see http://ltp.sourceforge.net/coverage/lcov.php ).

cmake -D ENABLE_COVERAGE_TESTING=true -D CMAKE_BUILD_TYPE=Debug .
make
lcov --capture --initial --directory . --output-file base.info --no-external
libraries/fc/bloom_test
libraries/fc/task_cancel_test
libraries/fc/api
libraries/fc/blind
libraries/fc/ecc_test test
libraries/fc/real128_test
libraries/fc/lzma_test README.md
libraries/fc/ntp_test
tests/intense_test
tests/app_test
tests/chain_bench
tests/chain_test
tests/performance_test
lcov --capture --directory . --output-file test.info --no-external
lcov --add-tracefile base.info --add-tracefile test.info --output-file total.info
lcov -o interesting.info -r total.info libraries/fc/vendor/\* libraries/fc/tests/\* tests/\*
mkdir -p lcov
genhtml interesting.info --output-directory lcov --prefix `pwd`
Now open lcov/index.html in a browser.

Unit testing
We use the Boost unit test framework for unit testing. Most unit tests reside in the chain_test build target.

Witness node
