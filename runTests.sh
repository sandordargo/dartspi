CURRENT_DIR=`pwd`
cd build && rm -rf * && conan install .. -s compiler.libcxx=libstdc++11 && cmake .. && make && (./tests/bin/DartsPi_tests_test)
cd "${CURRENT_DIR}"
