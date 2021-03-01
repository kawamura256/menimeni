#include"math.h"
#include"main.h"
#include"GameHead.h"

using namespace GameL;

//座標＋ベクトル
Point Add_Point_Vector(Point p, Vector v)
{
	Point r;
	r.x = p.x + v.x;
	r.y = p.y + v.y;

	return (r);
}

//ベクトル＋ベクトル
Vector Add_Vector_Vector(Vector v0, Vector v1)
{
	Vector r;
	r.x = v0.x + v1.x;
	r.y = v0.y + v1.y;

	return (r);
}

//ベクトル×スカラー
Vector Mul_Vector_Scaler(Vector v, float s)
{
	Vector r;
	r.x = v.x * s;
	r.y = v.y * s;

	return (r);
}

//ベクトルの長さを取得
float Vector_Length(Vector v)
{
	float l = sqrtf(v.x * v.x + v.y * v.y);
	return (l);
}

//ベクトルを正規化
Vector Vector_Normalize(Vector v)//Normalize=ノーマライズ＝ベクトルを正規化するやつ
{
	float l = Vector_Length(v);
	Vector n;
	n.x = v.x / l;
	n.y = v.y / l;

	return (n);
}


//ベクトルの長さを設定
Vector Vector_Set_Length(Vector v, float length)
{
	v = Vector_Normalize(v);
	v = Mul_Vector_Scaler(v, length);

	return (v);
}
//移動処理関数(一次元)
void Move(float* pos, float* speed, float acc)
{
	//加速度の影響を速度に与える
	*(speed) += acc;

	//速度の影響を座標に与える。
	*(pos) += *(speed);
}


//移動処理関数(二次元)
void Move(Point* pos, Vector* speed, Vector acc)
{
	*(speed) = Add_Vector_Vector(*(speed), acc);

	//速度の影響を座標に与える
	*(pos) = Add_Point_Vector(*(pos), *(speed));

}

//移動処理（摩擦あり）
void Move(float* pos, float* speed, float acc, float fri)
{
	//加速度の影響を速度に与える
	*(speed) += acc;
	//速度に摩擦の影響を与える
	*(speed) *= fri;
	//速度の影響を座標に与える
	*(pos) += *(speed);
}


