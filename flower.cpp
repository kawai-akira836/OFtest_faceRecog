//
//  flower.cpp
//  test_faceRecognition
//
//  Created by 川合暁 on 2019/01/29.
//

#include "flower.h"

//初期化処理---------------------------------------
void flower::init(string imagePlace) {
    image.load(imagePlace);
    count = ofRandom(1);
    oscSpeed = ofRandom(0.008, 0.013);
}

//更新処理(顔が検出できてない時)---------------------------------------
void flower::update() {
    //角度を更新
    count += oscSpeed;
}

//更新処理(顔が検出できた時)---------------------------------------
void flower::update(ofRectangle rect) {
    //角度を更新
    count += oscSpeed;
    
    //過去30回分の検出履歴をストア
    xHis.push_back(rect.x);
    yHis.push_back(rect.y);
    wHis.push_back(rect.width);
    hHis.push_back(rect.height);
    
    if (xHis.size() > 30) {
        xHis.erase(xHis.begin());
        yHis.erase(yHis.begin());
        wHis.erase(wHis.begin());
        hHis.erase(hHis.begin());
    }
    
    //検出履歴の平均を計算
    position.x = accumulate(xHis.begin(), xHis.end(), 0)/xHis.size();
    position.y = accumulate(yHis.begin(), yHis.end(), 0)/yHis.size();
    size.x = 0.3 * accumulate(wHis.begin(), wHis.end(), 0)/wHis.size();
    size.y = 0.3 * accumulate(hHis.begin(), hHis.end(), 0)/hHis.size();
}

//描画---------------------------------------
void flower::draw() {
    glBlendFunc(GL_ONE, GL_ONE);
    if (xHis.size() > 0) {
        this->rect.set(position, size.x, size.y);
        ofPushMatrix();
        ofTranslate(rect.getCenter());
        ofRotateDeg(sin(count)* 20);
        image.draw(-rect.width/2, -rect.height/2, rect.width, rect.height);
        ofPopMatrix();
    }
}

//描画---------------------------------------
void flower::draw(ofxCv::ObjectFinder finder) {
    
}

//力を加える---------------------------------------
void flower::addForce(glm::vec2 force){
    acceleration += force / mass;   //a = F/m
    
}

//力を加える---------------------------------------
void flower::addForce(float forceX, float forceY){
    acceleration += glm::vec2(forceX, forceY) / mass; //a = F/m
}

//コンストラクタ---------------------------------------
flower::flower() {
    
}
