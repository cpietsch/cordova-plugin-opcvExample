# cordova-plugin-opcvExample

- cordova plugin add https://github.com/cpietsch/cordova-plugin-opcvExample
- cordova platform remove android
- cordova platform add android

- dann folgende datei bearbeiten: platforms/android/of_v0.9.0_android_release/libs/openFrameworksCompiled/project/android/paths.make
- da muss der pfad zum android NDK angepasst werden (bei mir: ```NDK_ROOT=/Users/chris/Library/Android/sdk/ndk-bundle/```)


- settings.gradle soll so aussehen

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

- build.gradle sollte unter ```// SUB-PROJECT DEPENDENCIES``` END einmal ```compile project(':androidOpenCVExample')``` stehen
- dann gradle sync machen. das dauert ne weile, weil openframeworks für die maschiene gebuilded wird
- im platforms/android/AndroidManifest.xml muss die android:targetSdkVersion mindestens 22 sein (android:targetSdkVersion="21")


- wenn alles fertig ist kann der scanner so aufgerufen werden:
```
 $("#scan").click(function(){
    console.log("scan");

    opcvExample.startScan(function(result){
        alert("done "+result);
    });

})
```
