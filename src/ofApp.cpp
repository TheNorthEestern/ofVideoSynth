#include "ofApp.h"
#include <iostream>
using namespace std;

void ofApp::matrixPattern() {
    for (int y=-countY; y <= countY; y++) {
        ofPushMatrix();
        if (countY > 0) {
            float scale = ofMap(y, -countY, countY, 1 - pinchY, 1);
            ofScale(scale, scale);
        }
        ofTranslate(0, y * stepY);
        ofRotate( y * twistY );
        stripePattern();
        ofPopMatrix();
    }
}

void ofApp::stripePattern() {
    ofSetColor(color);
    ofSetLineWidth(1);
    filled ? ofFill() : ofNoFill();
    for (int i = -countX; i <= countX; i++) {
        ofPushMatrix();
        ofTranslate(i * stepX, 0);
        ofRotate(i * twistX);
        
        ofTranslate(0, shiftY);
        ofRotate(rotate);
        ofScale(size->x, size->y);
        type ? ofDrawRectangle(-50, -50, 100, 100):
               ofDrawTriangle(0, 0, -50, 100, 50, 100);
        
        ofPopMatrix();
    }
}

ofParameterGroup ofApp::configureTitle(string title) {
    ofParameterGroup a = ofParameterGroup();
    a.setName(title);
    return a;
}

//--------------------------------------------------------------
void ofApp::setup(){
    // string windowTitle = "Parameters";
    ofSetWindowTitle("Video Synth!");
    ofSetWindowShape(1280, 720);
    ofSetFrameRate(60);
    ofBackground(ofColor::azure);
    
    // image.allocate(600, 600, GL_RGBA);
    ofLoadImage(image, "collage.png");
    
    // parametersTitle.setName("Parameters");
    
    gui.setup(configureTitle("Parameters"), "settings.xml");
    gui.add(countX.setup("countX", 50, 0, 200));
    gui.add(stepX.setup("stepX", 20, 0, 200));
    gui.add(twistX.setup("twistX", 5, -45, 45));
    
    gui.add(countY.setup("countY", 0, 0, 50));
    gui.add(stepY.setup("stepY", 20, 0, 200));
    gui.add(twistY.setup("twistY", 0, -30, 30));
    gui.add(pinchY.setup("pinchY", 0, 0, 1));
    
    globalGroup.setup(configureTitle("Global"));
    globalGroup.add(Scale.setup("Scale", 1, 0.0, 1));
    globalGroup.add(Rotate.setup("Rotate", 0, -180, 180));
    globalGroup.add(Background.setup("Background", 255, 0, 255));
    gui.add(&globalGroup);
    
    primGroup.setup(configureTitle("Primitive"));
    primGroup.add(shiftY.setup("shiftY", 0.0, -1000.0, 1000.0));
    primGroup.add(rotate.setup("rotate", 0.0, -180.0, 180.0));
    primGroup.add(size.setup("size", ofVec2f(6,6), ofVec2f(0,0), ofVec2f(20, 20)));
    primGroup.add(color.setup("color", ofColor::black, ofColor(0,0,0,0),ofColor::white));
    primGroup.add(filled.setup("filled", false));
    primGroup.add(type.setup("type", false));
    
    
    
    gui.add(&primGroup);
    
    gui.loadFromFile(settingsFileName);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(Background);
    
    ofSetColor(255);
    image.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    float Scl = pow((double)Scale, 4.0);
    ofScale(Scl, Scl);
    ofRotate(Rotate);
    
    // Drawing code goes here.
    matrixPattern();
    ofPopMatrix();
    
    showGui ? gui.draw() : void();
}

void ofApp::exit() {
    gui.saveToFile(settingsFileName);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofFileDialogResult saveResult, loadResult;
    switch(key) {
        case 'z':
            showGui = !showGui;
            break;
        
        case OF_KEY_RETURN:
            ofSaveScreen("screenshot.png");
            break;
        
        case 's':
            saveResult = ofSystemSaveDialog("preset.xml", "Saving Preset");
            if ( saveResult.bSuccess ) gui.saveToFile(saveResult.filePath);
            break;
        
        case 'l':
            loadResult = ofSystemLoadDialog("Loading Preset");
            if (loadResult.bSuccess) gui.loadFromFile(loadResult.filePath);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
