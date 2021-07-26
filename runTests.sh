CURRENT_DIR=`pwd`
cd build && rm -rf * && conan install .. -s compiler.version=10 -s compiler.libcxx=libstdc++11  && cmake .. && make && (./tests/bin/DartsPi_tests_test)
cd "${CURRENT_DIR}"
