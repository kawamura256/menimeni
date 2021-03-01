#include"math.h"
#include"main.h"
#include"GameHead.h"

using namespace GameL;

//���W�{�x�N�g��
Point Add_Point_Vector(Point p, Vector v)
{
	Point r;
	r.x = p.x + v.x;
	r.y = p.y + v.y;

	return (r);
}

//�x�N�g���{�x�N�g��
Vector Add_Vector_Vector(Vector v0, Vector v1)
{
	Vector r;
	r.x = v0.x + v1.x;
	r.y = v0.y + v1.y;

	return (r);
}

//�x�N�g���~�X�J���[
Vector Mul_Vector_Scaler(Vector v, float s)
{
	Vector r;
	r.x = v.x * s;
	r.y = v.y * s;

	return (r);
}

//�x�N�g���̒������擾
float Vector_Length(Vector v)
{
	float l = sqrtf(v.x * v.x + v.y * v.y);
	return (l);
}

//�x�N�g���𐳋K��
Vector Vector_Normalize(Vector v)//Normalize=�m�[�}���C�Y���x�N�g���𐳋K��������
{
	float l = Vector_Length(v);
	Vector n;
	n.x = v.x / l;
	n.y = v.y / l;

	return (n);
}


//�x�N�g���̒�����ݒ�
Vector Vector_Set_Length(Vector v, float length)
{
	v = Vector_Normalize(v);
	v = Mul_Vector_Scaler(v, length);

	return (v);
}
//�ړ������֐�(�ꎟ��)
void Move(float* pos, float* speed, float acc)
{
	//�����x�̉e���𑬓x�ɗ^����
	*(speed) += acc;

	//���x�̉e�������W�ɗ^����B
	*(pos) += *(speed);
}


//�ړ������֐�(�񎟌�)
void Move(Point* pos, Vector* speed, Vector acc)
{
	*(speed) = Add_Vector_Vector(*(speed), acc);

	//���x�̉e�������W�ɗ^����
	*(pos) = Add_Point_Vector(*(pos), *(speed));

}

//�ړ������i���C����j
void Move(float* pos, float* speed, float acc, float fri)
{
	//�����x�̉e���𑬓x�ɗ^����
	*(speed) += acc;
	//���x�ɖ��C�̉e����^����
	*(speed) *= fri;
	//���x�̉e�������W�ɗ^����
	*(pos) += *(speed);
}


