#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    iterations = 128;
    
    img.load("face.jpg");
    
    w = img.getWidth();
    h = img.getHeight();
    
    ofSetWindowShape(w, h);
    
    fboStretch.allocate(w*2, h*0.5, GL_RGBA);
    fboCut.allocate(w, h, GL_RGBA);
    fboRotate.allocate(w, h, GL_RGBA);
    
    fboStretch.getTexture().setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
    fboCut.getTexture().setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
    fboRotate.getTexture().setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
    
    fboRotate.begin();
        img.draw(0,0);
    fboRotate.end();
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i<iterations; i++){
        fboStretch.begin();
            fboRotate.draw(0,0,w*2, h*0.5);
        fboStretch.end();
        
        fboCut.begin();
            fboStretch.draw(0,0);
            fboStretch.draw(fboStretch.getWidth(), fboStretch.getHeight() + h*0.5, -fboStretch.getWidth(), -fboStretch.getHeight());
        fboCut.end();
        
        fboRotate.begin();
            ofPushMatrix();
            ofTranslate(w/2, h/2);
            ofRotate(90);
                fboCut.draw(-w/2,-h/2);
            ofPopMatrix();
        fboRotate.end();
    }
    
    fboRotate.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
