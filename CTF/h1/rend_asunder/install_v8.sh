RPATH=`pwd`

git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
$RPATH/depot_tools/fetch v8
$RPATH/v8/build/install-build-deps.sh

# Go to 6.7.1 version
git checkout e1de5c822d8fe7db4a1d80d15e7ea4a771c5f32f

$RPATH/depot_tools/gclient sync
cd $RPATH/v8/
./tools/dev/v8gen.py x64.debug
$RPATH/depot_tools/ninja -C ./out.gn/x64.debug