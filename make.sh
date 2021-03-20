# make pushd and popd quiet!
pushd () {
    command pushd "$@" > /dev/null
}
popd () {
    command popd "$@" > /dev/null
}

# remove old files
rm -f bin/*
rm -f *.exe
echo "Removed old compiled files"

# call make
make

# run main
pushd "./bin"
./main.exe
popd