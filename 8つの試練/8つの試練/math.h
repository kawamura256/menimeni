#pragma once

//2次元移動への対応

//座標情報の構造体
struct Point
{
	float x, y;
};

//ベクトルの構造体
struct Vector
{
	float x, y;
};

//座標＋ベクトル
Point Add_Point_Vector(Point p, Vector v);
//ベクトル＋ベクトル
Vector Add_Vector_Vector(Vector v0, Vector v1);
//ベクトル×スカラー
Vector Mul_Vector_Scaler(Vector v, float s);
//ベクトルの長さを取得
float Vector_Length(Vector v);
//ベクトルを正規化
Vector Vector_Normalize(Vector);
//ベクトルの長さを設定
Vector Vector_Set_Length(Vector v, float length);

//移動処理
void Move(Point* pos, Vector* speed, Vector acc);

//摩擦
void Move(float* pos, float* speed, float acc, float fri);


