# cordova-plugin-opcvExample

## install
- cordova plugin add https://github.com/cpietsch/cordova-plugin-opcvExample
- cordova platform remove android
- cordova platform add android

## aftermath 
- edit this file: `platforms/android/of_v0.9.0_android_release/libs/openFrameworksCompiled/project/android/paths.make`
- change the path of your android NDK (mine on OSX: `NDK_ROOT=/Users/chris/Library/Android/sdk/ndk-bundle/`)


- `settings.gradle` should look like this

```
// GENERATED FILE - DO NOT EDIT
include ":"
include ":CordovaLib"
//Extras From OpenCV project start here
include ":androidOpenCVExample"
project(':androidOpenCVExample').projectDir = new File('of_v0.9.0_android_release/apps/myApps/androidOpenCVExample')
def ofRoot = 'of_v0.9.0_android_release/'
include ':ofAndroidLib'
project(':ofAndroidLib').projectDir = new File(ofRoot + 'addons/ofxAndroid/ofAndroidLib')
include ':openFrameworksProject'
project(':openFrameworksProject').projectDir = new File(ofRoot + 'libs/openFrameworksCompiled/project/android')
include ':openFrameworks'
project(':openFrameworks').projectDir = new File(ofRoot + 'libs/openFrameworks')
//Extras From OpenCV project end here
```

- `build.gradle` should have after ```// SUB-PROJECT DEPENDENCIES END``` once  ```compile project(':androidOpenCVExample')``` 
- make sure `platforms/android/AndroidManifest.xml` should have `android:targetSdkVersion="22"` (at least 22)
- make a gradle sync for openframeworks to be build

## js
- you can call the of app like this
```
 $("#scan").click(function(){
    console.log("scan");

    opcvExample.startScan(function(result){
        alert("done "+result);
    });

})
```
