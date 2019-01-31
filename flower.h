//
//  flower.hpp
//  test_faceRecognition
//
//  Created by 川合暁 on 2019/01/29.
//

#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class flower {
public:
    void init(string imagePlace);           //初期化処理(画像読み込み等)
    void update(ofRectangle rect);          //更新処理(顔が検出できた時用)
    void update();                          //更新処理(顔が検出できなかった時用)
    void draw();                            //描画処理
   
    //物体に力を加える
    void addForce(glm::vec2 force);
    void addForce(float forceX, float forceY);
    
    
    ofRectangle rect;
    ofImage image;
    
    //画像検出結果の履歴
    vector <float> xHis;
    vector <float> yHis;
    vector <float> wHis;
    vector <float> hHis;
    
    float oscSpeed;     //角度の振動のスピード
    float count = 0;    //角度
    
    glm::vec2 position;  //位置
    glm::vec2 size;      //大きさ
    
    flower();   //コンストラクタ

    
    //以下まだ実装してない
    void draw(ofxCv::ObjectFinder finder);
    glm::vec2 velocity;  //速度
    glm::vec2 acceleration; //加速度
    int colorR, colorG, colorB;
    float radius;
    float friction;
    float mass;
    };
