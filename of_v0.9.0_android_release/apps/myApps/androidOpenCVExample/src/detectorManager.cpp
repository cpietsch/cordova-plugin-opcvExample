//
// Created by Abdul Sami on 24/03/16.
//

#include "detectorManager.h"
#include "ofApp.h"


void DetectorManager::detectionCallback(int code){
    // we have winner!
    // this code should now be returned into
    // the cordova js callback of the plugin
    this->app->sendDetectionResultStringtoJava(ofToString(code));

    detectedCodeCount = 0;
    detectedCode = 0;

    detectorRed.clean();
    detectorOrange.clean();
    detectorGreen.clean();

    cout << "FOUND ERROR CODE " << ofToString(code) << endl;
}