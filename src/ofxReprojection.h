#pragma once

// This class is used for convenient and simple integration of
//  - ofxReprojectionCalibration
//  - ofxReprojectionRenderer

#include "ofMain.h"
#include "ofxBase3DVideo.h"
#include "ofxReprojectionCalibration.h"
#include "ofxReprojectionRenderer.h"

class ofxReprojection {
public:
		ofxReprojection();
		~ofxReprojection();
		bool init(ofxBase3DVideo* cam, string calibration_file = "");
		void update();
		void drawCalibrationStatusScreen();

        void draw(ofTexture depthTexture, ofTexture userTexture, float pointsize, bool use_transform, bool use_depthimage);
        void draw();

        void drawTransHueImg();

        void end();

        ofMatrix4x4 getProjectionMatrix() {return renderer.getProjectionMatrix();}
        int getProjWidth() { return renderer.getProjWidth();}
        int getProjHeight() { return renderer.getProjHeight();}
        int getCamWidth() { return renderer.getCamWidth();}
        int getCamHeight() {return renderer.getCamHeight();}
        float getMaxDepth() {return renderer.getMaxDepth();}

private:
		bool bCalibrationStage;
		ofxBase3DVideo* cam;
		ofxReprojectionCalibration calibration;
		ofxReprojectionCalibrationData calibrationData;
		ofMatrix4x4 calibrationMatrix;
		ofxReprojectionRenderer renderer;

};
