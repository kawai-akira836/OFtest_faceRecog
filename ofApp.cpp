#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.initGrabber(ofGetWidth(), ofGetHeight());   //カメラ取得開始
    
    //顔検出をセットアップ
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset(ofxCv::ObjectFinder::Fast);
    
    
    //画像読み込み
    for (int i = 0; i < FL_NUM; i++) {
        string filename = ".png";
        filename = to_string(4) + filename; //ファイルの名前をここで決めている
        fl[i].init(filename);
    }
   
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();   //カメラの更新
    
    if (cam.isFrameNew()) {
        finder.update(cam); //顔検出
    }
    
    //顔が検出できなかった場合角度だけ回す
    if (finder.size() == 0) {
        for (int j = 0; j < FL_NUM; j++) {
            fl[j].update();
        }
        
    //顔が検出できた場合flowerたちに顔検出データを送る
    } else {
        for(int i=0; i<finder.size(); i++){
            for (int j = 0; j < FL_NUM; j++) {
                ofRectangle rect = finder.getObjectSmoothed(i);
                
                //円形にflowerたちを並べる
                rect.setX(rect.x + 0.35 * rect.width - fl[j].size.x * 2 * cos((j * 40 + 10)*DEG_TO_RAD));
                rect.setY(rect.y - fl[j].size.x * 2 * sin((j * 40 + 10)*DEG_TO_RAD));
                
                fl[j].update(rect);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //カメラの結果を描画
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ofSetColor(255);
    cam.draw(0, 0);
    
    //少し暗く
    ofSetColor(40, 40, 40, 0);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //flower達を描写
    ofSetColor(150);
    float minLength = 100000;
    for (int j = 0; j < FL_NUM; j++) {
        fl[j].draw();
    }
    
    count++;
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
