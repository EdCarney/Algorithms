# make pushd and popd quiet!
pushd () {
    command pushd "$@" > /dev/null
}
popd () {
    command popd "$@" > /dev/null
}

# remove old files
if [ -d "bin" ]
then
    rm -f bin/*
else
    mkdir bin
fi
rm -f *.exe
echo "Removed old compiled files"

# call make
make

# run main
pushd "./bin"
./main.exe
popd