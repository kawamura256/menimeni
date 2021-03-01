#pragma once

//2�����ړ��ւ̑Ή�

//���W���̍\����
struct Point
{
	float x, y;
};

//�x�N�g���̍\����
struct Vector
{
	float x, y;
};

//���W�{�x�N�g��
Point Add_Point_Vector(Point p, Vector v);
//�x�N�g���{�x�N�g��
Vector Add_Vector_Vector(Vector v0, Vector v1);
//�x�N�g���~�X�J���[
Vector Mul_Vector_Scaler(Vector v, float s);
//�x�N�g���̒������擾
float Vector_Length(Vector v);
//�x�N�g���𐳋K��
Vector Vector_Normalize(Vector);
//�x�N�g���̒�����ݒ�
Vector Vector_Set_Length(Vector v, float length);

//�ړ�����
void Move(Point* pos, Vector* speed, Vector acc);

//���C
void Move(float* pos, float* speed, float acc, float fri);


