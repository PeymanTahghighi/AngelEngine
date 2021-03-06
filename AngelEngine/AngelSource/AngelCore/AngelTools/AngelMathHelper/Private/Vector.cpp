#include"../Public/Vector.h"

#include<utility>

#include<assert.h>

#include<cmath>

#define PI 3.14159265

#pragma region Vector2D

AngelCore::Vector<2>::Vector()
{
	this->m_x = 0.0f;
	this->m_y = 0.0f;
}

AngelCore::Vector<2>::Vector(float _first, float _second)
{
	this->m_x = _first;
	this->m_y = _second;
}

AngelCore::Vector<2>::Vector(DirectX::XMFLOAT2 vec)
{
	this->m_x = vec.x;
	this->m_y = vec.y;
}

AngelCore::Vector<2>::~Vector()
{

}

AngelCore::Vector<2>::Vector(const Vector &that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
}

AngelCore::Vector<2>::Vector(Vector &&that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
}

AngelCore::Vector<2>& AngelCore::Vector<2>::operator=(const Vector &that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
	return *this;
}

AngelCore::Vector<2> & AngelCore::Vector<2>::operator=(Vector &&that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
	
	return *this;
}

AngelCore::Vector<2> & AngelCore::Vector<2>::operator+(const Vector &rhs)
{
	this->m_x += rhs.m_x;
	this->m_y += rhs.m_y;
	return *this;
}


AngelCore::Vector<2> &AngelCore::Vector<2>::operator-(const Vector &rhs)
{
	this->m_x -= rhs.m_x;
	this->m_y -= rhs.m_y;
	return *this;
}

AngelCore::Vector<2> &AngelCore::Vector<2>::operator++()
{
	this->m_x++;
	this->m_y++;
	return *this;
}

AngelCore::Vector<2> &AngelCore::Vector<2>::operator++(int)
{
	this->m_x ++;
	this->m_y ++;
	return *this;
}

AngelCore::Vector<2> &AngelCore::Vector<2>::operator--()
{
	this->m_x--;
	this->m_y--;
	return *this;
}
AngelCore::Vector<2> &AngelCore::Vector<2>::operator--(int)
{
	this->m_x --;
	this->m_y --;
	return *this;
}

const bool AngelCore::Vector<2>::operator==(const Vector &rhs) const
{
	if (this->m_x == rhs.m_x && this->m_y == this->m_y)
		return true;

	return false;
}
bool AngelCore::Vector<2>::operator==(const Vector &rhs)
{
	if (this->m_x == rhs.m_x && this->m_y == this->m_y)
		return true;

	return false;
}

bool AngelCore::Vector<2>::operator!=(const Vector &rhs)
{
	if (this->m_x != rhs.m_x || this->m_y != rhs.m_y)
		return true;
	return false;
}


const bool AngelCore::Vector<2>::operator!=(const Vector &rhs) const
{
	if (this->m_x != rhs.m_x || this->m_y != rhs.m_y)
		return true;
	return false;
}

bool AngelCore::Vector<2>::operator<(const Vector &rhs) 
{
	if (this->m_x < rhs.m_x && this->m_y < rhs.m_y)
		return true;

	return false;
}

const bool AngelCore::Vector<2>::operator<(const Vector &rhs) const
{
	if (this->m_x < rhs.m_x && this->m_y < rhs.m_y)
		return true;

	return false;
}


bool AngelCore::Vector<2>::operator<=(const Vector &rhs)
{
	if (*this < rhs || *this == rhs)
		return true;

	return false;
}

const bool AngelCore::Vector<2>::operator<=(const Vector &rhs) const
{
	if (*this < rhs || *this == rhs)
		return true;

	return false;
}

bool AngelCore::Vector<2>::operator>(const Vector &rhs)
{
	if (this->m_x > rhs.m_x && this->m_y>rhs.m_y)
		return true;

	return false;
}

const bool AngelCore::Vector<2>::operator>(const Vector &rhs) const
{
	if (this->m_x > rhs.m_x && this->m_y > rhs.m_y)
		return true;

	return false;
}

bool AngelCore::Vector<2>::operator>=(const Vector &rhs)
{
	if (*this > rhs || *this == rhs)
		return true;

	return false;
}

const bool AngelCore::Vector<2>::operator>=(const Vector &rhs) const
{
	if (*this > rhs || *this == rhs)
		return true;

	return false;
}


float AngelCore::Vector<2>::operator[](int i)
{
	assert(i < 2);
	switch (i)
	{
	case 1:
		return this->m_x;
	case 2:
		return this->m_y;
	}
	return -1;
}

const float AngelCore::Vector<2>::operator[](int i) const
{
	assert(i < 2);
	switch (i)
	{
	case 1:
		return this->m_x;
	case 2:
		return this->m_y;
	}
	return -1;
}

AngelCore::Vector<2> &AngelCore::Vector<2>::operator+=(const Vector &rhs)
{
	this->m_x += rhs.m_x;
	this->m_y += rhs.m_y;

	return *this;
}


AngelCore::Vector<2> &AngelCore::Vector<2>::operator-=(const Vector &rhs)
{
	this->m_x -= rhs.m_x;
	this->m_y -= rhs.m_y;

	return *this;
}


DirectX::XMFLOAT2 AngelCore::Vector<2>::GetXMFLOAT2() const
{
	return DirectX::XMFLOAT2(this->m_x, this->m_y);
}

DirectX::XMVECTOR AngelCore::Vector<2>::GetXMVECTOR() const
{
	return DirectX::XMVectorSet(this->m_x, this->m_y, 0.0f, 0.0f);
}

float AngelCore::Vector<2>::Magnitude()
{
	return std::sqrt(std::pow(this->m_x, 2) + std::pow(this->m_y, 2));
}

const float AngelCore::Vector<2>::Magnitude() const
{
	return std::sqrt(std::pow(this->m_x, 2) + std::pow(this->m_y, 2));
}

float AngelCore::Vector<2>::Distance(const Vector &rhs)
{
	Vector AtoB;
	AtoB.m_x = this->m_x;
	AtoB.m_y = this->m_y;
	AtoB -= rhs;
	return AtoB.Magnitude();
}

const float AngelCore::Vector<2>::Distance(Vector const &rhs) const
{
	Vector AtoB;
	AtoB.m_x = this->m_x;
	AtoB.m_y = this->m_y;
	AtoB -= rhs;
	return AtoB.Magnitude();
}

float AngelCore::Vector<2>::Dot(const Vector &rhs)
{
	return (this->m_x * rhs.m_x) + (this->m_y * rhs.m_y);
}


const float AngelCore::Vector<2>::Dot(const Vector &rhs) const
{
	return (this->m_x * rhs.m_x) + (this->m_y * rhs.m_y);
}

float AngelCore::Vector<2>::Angle(const Vector &rhs)
{
	float Dot = this->Dot(rhs);
	float MagA = this->Magnitude();
	float MagB = rhs.Magnitude();
	float data = acosf(Dot / (MagA*MagB));
	return static_cast<float>((data * 180) / PI);
}

const float AngelCore::Vector<2>::Angle(const Vector &rhs) const
{
	float Dot = this->Dot(rhs);
	float MagA = this->Magnitude();
	float MagB = rhs.Magnitude();
	float data = (MagA*MagB) / Dot;
	return static_cast<float>((data * 180) / PI);
}
#pragma endregion

#pragma region Vector3D

AngelCore::Vector<3>::Vector()
{
	this->m_x = 0.0f;
	this->m_y = 0.0f;
	this->m_z = 0.0f;
}

AngelCore::Vector<3>::Vector(float _first, float _second,float _third)
{
	this->m_x = _first;
	this->m_y = _second;
	this->m_z = _third;
}

AngelCore::Vector<3>::Vector(DirectX::XMVECTOR vec)
{
	this->m_x = vec.m128_f32[0];
	this->m_y = vec.m128_f32[1];
	this->m_z = vec.m128_f32[2];
}
AngelCore::Vector<3>::Vector(DirectX::XMFLOAT3 vec)
{
	this->m_x = vec.x;
	this->m_y = vec.y;
	this->m_z = vec.z;
}

AngelCore::Vector<3>::~Vector()
{
	
}

AngelCore::Vector<3>::Vector(const Vector &that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
	this->m_z = that.m_z;
}

AngelCore::Vector<3>::Vector(Vector &&that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
	this->m_z = that.m_z;
}

AngelCore::Vector<3>& AngelCore::Vector<3>::operator=(const Vector &that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
	this->m_z = that.m_z;

	return *this;
}

AngelCore::Vector<3> & AngelCore::Vector<3>::operator=(Vector &&that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
	this->m_z = that.m_z;


	return *this;
}

AngelCore::Vector<3> & AngelCore::Vector<3>::operator+(const Vector &rhs)
{
	this->m_x += rhs.m_x;
	this->m_y += rhs.m_y;
	this->m_z += rhs.m_z;

	return *this;
}


AngelCore::Vector<3> &AngelCore::Vector<3>::operator-(const Vector &rhs)
{
	this->m_x -= rhs.m_x;
	this->m_y -= rhs.m_y;
	this->m_z -= rhs.m_z;

	return *this;
}

AngelCore::Vector<3> &AngelCore::Vector<3>::operator++()
{
	this->m_x++;
	this->m_y++;
	this->m_z++;

	return *this;
}

AngelCore::Vector<3> &AngelCore::Vector<3>::operator++(int)
{
	this->m_x ++;
	this->m_y ++;
	this->m_z ++;

	return *this;
}

AngelCore::Vector<3> &AngelCore::Vector<3>::operator--()
{
	this->m_x--;
	this->m_y--;
	this->m_z--;

	return *this;
}
AngelCore::Vector<3> &AngelCore::Vector<3>::operator--(int)
{
	this->m_x --;
	this->m_y --;
	this->m_z --;

	return *this;
}

const bool AngelCore::Vector<3>::operator==(const Vector &rhs) const
{
	if (this->m_x == rhs.m_x && this->m_y == this->m_y && this->m_z == this->m_z)
		return true;

	return false;
}
bool AngelCore::Vector<3>::operator==(const Vector &rhs)
{
	if (this->m_x == rhs.m_x && this->m_y == this->m_y && this->m_z == this->m_z)
		return true;

	return false;
}

bool AngelCore::Vector<3>::operator!=(const Vector &rhs)
{
	if (this->m_x != rhs.m_x || this->m_y != rhs.m_y || this->m_z != rhs.m_z)
		return true;
	return false;
}


const bool AngelCore::Vector<3>::operator!=(const Vector &rhs) const
{
	if (this->m_x != rhs.m_x || this->m_y != rhs.m_y || this->m_z != rhs.m_z)
		return true;
	return false;
}

bool AngelCore::Vector<3>::operator<(const Vector &rhs)
{
	if (this->m_x < rhs.m_x && this->m_y < rhs.m_y && this->m_z < rhs.m_z)
		return true;

	return false;
}

const bool AngelCore::Vector<3>::operator<(const Vector &rhs) const
{
	if (this->m_x < rhs.m_x && this->m_y < rhs.m_y && this->m_z < rhs.m_z)
		return true;

	return false;
}


bool AngelCore::Vector<3>::operator<=(const Vector &rhs)
{
	if (*this < rhs || *this == rhs)
		return true;

	return false;
}

const bool AngelCore::Vector<3>::operator<=(const Vector &rhs) const
{
	if (*this < rhs || *this == rhs)
		return true;

	return false;
}

bool AngelCore::Vector<3>::operator>(const Vector &rhs)
{
	if (this->m_x > rhs.m_x && this->m_y>rhs.m_y && this->m_z>rhs.m_z)
		return true;

	return false;
}

const bool AngelCore::Vector<3>::operator>(const Vector &rhs) const
{
	if (this->m_x > rhs.m_x && this->m_y > rhs.m_y && this->m_z > rhs.m_z)
		return true;

	return false;
}

bool AngelCore::Vector<3>::operator>=(const Vector &rhs)
{
	if (*this > rhs || *this == rhs)
		return true;

	return false;
}

const bool AngelCore::Vector<3>::operator>=(const Vector &rhs) const
{
	if (*this > rhs || *this == rhs)
		return true;

	return false;
}


float AngelCore::Vector<3>::operator[](int i)
{
	assert(i < 3);
	switch (i)
	{
	case 1: 
		return this->m_x;
		break;
	case 2:
		return this->m_y;
		break;
	case 3:
		return this->m_z;
		break;
	}
	return -1;
}

const float AngelCore::Vector<3>::operator[](int i) const
{
	assert(i < 3);
	switch (i)
	{
	case 1:
		return this->m_x;
		break;
	case 2:
		return this->m_y;
		break;
	case 3:
		return this->m_z;
		break;
	}
	return -1;
}

AngelCore::Vector<3> &AngelCore::Vector<3>::operator+=(const Vector &rhs)
{
	this->m_x += rhs.m_x;
	this->m_y += rhs.m_y;
	this->m_z += rhs.m_z;
	return *this;
}


AngelCore::Vector<3> &AngelCore::Vector<3>::operator-=(const Vector &rhs)
{
	this->m_x -= rhs.m_x;
	this->m_y -= rhs.m_y;
	this->m_z -= rhs.m_z;
	return *this;
}


DirectX::XMFLOAT3 AngelCore::Vector<3>::GetXMFLOAT3() const
{
	return DirectX::XMFLOAT3(this->m_x, this->m_y,this->m_z);
}

DirectX::XMVECTOR AngelCore::Vector<3>::GetXMVECTOR() const
{
	return DirectX::XMVectorSet(this->m_x, this->m_y, this->m_z, 0.0f);
}

float AngelCore::Vector<3>::Magnitude()
{
	return std::sqrt(std::pow(this->m_x, 2) + std::pow(this->m_y, 2) + std::pow(this->m_z, 2));
}

const float AngelCore::Vector<3>::Magnitude() const
{
	return std::sqrt(std::pow(this->m_x, 2) + std::pow(this->m_y, 2) + std::pow(this->m_z, 2));
}

float AngelCore::Vector<3>::Distance(const Vector &rhs)
{
	Vector AtoB;
	AtoB.m_x = this->m_x;
	AtoB.m_y = this->m_y;
	AtoB.m_z = this->m_z;
	AtoB -= rhs;
	return AtoB.Magnitude();
}

const float AngelCore::Vector<3>::Distance(Vector const &rhs) const
{
	Vector AtoB;
	AtoB.m_x = this->m_x;
	AtoB.m_y = this->m_y;
	AtoB.m_z = this->m_z;
	AtoB -= rhs;
	return AtoB.Magnitude();
}

float AngelCore::Vector<3>::Dot(const Vector &rhs)
{
	return (this->m_x * rhs.m_x) + (this->m_y * rhs.m_y) + (this->m_z * rhs.m_z);
}


const float AngelCore::Vector<3>::Dot(const Vector &rhs) const
{
	return (this->m_x * rhs.m_x) + (this->m_y * rhs.m_y) + (this->m_z * rhs.m_z);
}

float AngelCore::Vector<3>::Angle(const Vector &rhs)
{
	return static_cast<float>(((acosf(this->Dot(rhs) / (this->Magnitude()*rhs.Magnitude())) * 180) / PI));
}

const float AngelCore::Vector<3>::Angle(const Vector &rhs) const
{
	return static_cast<float>(((acosf(this->Dot(rhs) / (this->Magnitude()*rhs.Magnitude())) * 180) / PI));
}

AngelCore::Vector<3> AngelCore::Vector<3>::Normalize()
{
	float mag = Magnitude();
	this->m_x /= mag;
	this->m_y /= mag;
	this->m_z /= mag;
	return *this;
}

AngelCore::Vector<3> AngelCore::Vector<3>::Multiply(float &num)
{
	using namespace DirectX;
	DirectX::XMVECTOR tmp(GetXMVECTOR());
	tmp = num*tmp;
	return tmp;
}
#pragma endregion

#pragma region Vector4D

AngelCore::Vector<4>::Vector()
{
	

	this->m_x = 0.0f;
	this->m_y = 0.0f;
	this->m_z = 0.0f;
	this->m_w = 0.0f;

}

AngelCore::Vector<4>::Vector(float _first, float _second, float _third, float _forth)
{

	this->m_x = _first;
	this->m_y = _second;
	this->m_z = _third;
	this->m_w = _forth;

}

AngelCore::Vector<4>::~Vector()
{
	
}

AngelCore::Vector<4>::Vector(const Vector &that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
	this->m_z = that.m_z;
	this->m_w = that.m_w;

}

AngelCore::Vector<4>::Vector(Vector &&that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
	this->m_z = that.m_z;
	this->m_w = that.m_w;

}

AngelCore::Vector<4>& AngelCore::Vector<4>::operator=(const Vector &that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
	this->m_z = that.m_z;
	this->m_w = that.m_w;

	return *this;
}

AngelCore::Vector<4> & AngelCore::Vector<4>::operator=(Vector &&that)
{
	this->m_x = that.m_x;
	this->m_y = that.m_y;
	this->m_z = that.m_z;
	this->m_w = that.m_w;

	return *this;
}

AngelCore::Vector<4> & AngelCore::Vector<4>::operator+(const Vector &rhs)
{
	this->m_x += rhs.m_x;
	this->m_y += rhs.m_y;
	this->m_z += rhs.m_z;
	this->m_w += rhs.m_w;

	return *this;
}


AngelCore::Vector<4> &AngelCore::Vector<4>::operator-(const Vector &rhs)
{
	this->m_x -= rhs.m_x;
	this->m_y -= rhs.m_y;
	this->m_z -= rhs.m_z;
	this->m_w -= rhs.m_w;

	return *this;
}

AngelCore::Vector<4> &AngelCore::Vector<4>::operator++()
{
	this->m_x++;
	this->m_y++;
	this->m_z++;
	this->m_w++;

	return *this;
}

AngelCore::Vector<4> &AngelCore::Vector<4>::operator++(int)
{
	this->m_x ++;
	this->m_y ++;
	this->m_z ++;
	this->m_w ++;

	return *this;
}

AngelCore::Vector<4> &AngelCore::Vector<4>::operator--()
{
	this->m_x --;
	this->m_y --;
	this->m_z --;
	this->m_w --;

	return *this;
}
AngelCore::Vector<4> &AngelCore::Vector<4>::operator--(int)
{
	this->m_x --;
	this->m_y --;
	this->m_z --;
	this->m_w --;

	return *this;
}

const bool AngelCore::Vector<4>::operator==(const Vector &rhs) const
{
	if (this->m_x == rhs.m_x && this->m_y == this->m_y && this->m_z == this->m_z && this->m_w == this->m_w)
		return true;

	return false;
}
bool AngelCore::Vector<4>::operator==(const Vector &rhs)
{
	if (this->m_x == rhs.m_x && this->m_y == this->m_y && this->m_z == this->m_z && this->m_w == this->m_w)
		return true;

	return false;
}

bool AngelCore::Vector<4>::operator!=(const Vector &rhs)
{
	if (this->m_x != rhs.m_x || this->m_y != rhs.m_y || this->m_z != rhs.m_z || this->m_w != rhs.m_w)
		return true;
	return false;
}


const bool AngelCore::Vector<4>::operator!=(const Vector &rhs) const
{
	if (this->m_x != rhs.m_x || this->m_y != rhs.m_y || this->m_z != rhs.m_z || this->m_w != rhs.m_w)
		return true;
	return false;
}

bool AngelCore::Vector<4>::operator<(const Vector &rhs)
{
	if (this->m_x < rhs.m_x && this->m_y < rhs.m_y && this->m_z < rhs.m_z && this->m_w < rhs.m_w)
		return true;

	return false;
}

const bool AngelCore::Vector<4>::operator<(const Vector &rhs) const
{
	if (this->m_x < rhs.m_x && this->m_y < rhs.m_y && this->m_z < rhs.m_z && this->m_w < rhs.m_w)
		return true;

	return false;
}


bool AngelCore::Vector<4>::operator<=(const Vector &rhs)
{
	if (*this < rhs || *this == rhs)
		return true;

	return false;
}

const bool AngelCore::Vector<4>::operator<=(const Vector &rhs) const
{
	if (*this < rhs || *this == rhs)
		return true;

	return false;
}

bool AngelCore::Vector<4>::operator>(const Vector &rhs)
{
	if (this->m_x > rhs.m_x && this->m_y>rhs.m_y && this->m_z>rhs.m_z && this->m_w>rhs.m_w)
		return true;

	return false;
}

const bool AngelCore::Vector<4>::operator>(const Vector &rhs) const
{
	if (this->m_x > rhs.m_x && this->m_y>rhs.m_y && this->m_z>rhs.m_z && this->m_w>rhs.m_w)
		return true;

	return false;
}

bool AngelCore::Vector<4>::operator>=(const Vector &rhs)
{
	if (*this > rhs || *this == rhs)
		return true;

	return false;
}

const bool AngelCore::Vector<4>::operator>=(const Vector &rhs) const
{
	if (*this > rhs || *this == rhs)
		return true;

	return false;
}


float AngelCore::Vector<4>::operator[](int i)
{
	assert(i < 4);
	switch (i)
	{
	case 0:
		return this->m_x;
		break;
	case 1:
		return this->m_y;
		break;
	case 2:
		return this->m_z;
		break;
	case 3:
		return this->m_w;
		break;
	}
	return -1;
}

const float AngelCore::Vector<4>::operator[](int i) const
{
	assert(i < 4);
	switch (i)
	{
	case 0:
		return this->m_x;
		break;
	case 1:
		return this->m_y;
		break;
	case 2:
		return this->m_z;
		break;
	case 3:
		return this->m_w;
		break;
	}
	return -1;
}

AngelCore::Vector<4> &AngelCore::Vector<4>::operator+=(const Vector &rhs)
{
	this->m_x += rhs.m_x;
	this->m_y += rhs.m_y;
	this->m_z += rhs.m_z;
	this->m_w += rhs.m_w;

	return *this;
}


AngelCore::Vector<4> &AngelCore::Vector<4>::operator-=(const Vector &rhs)
{
	this->m_x -= rhs.m_x;
	this->m_y -= rhs.m_y;
	this->m_z -= rhs.m_z;
	this->m_w -= rhs.m_w;

	return *this;
}


DirectX::XMFLOAT4 AngelCore::Vector<4>::GetXMFLOAT4() const
{
	return DirectX::XMFLOAT4(this->m_x, this->m_y, this->m_z,this->m_w);
}

DirectX::XMVECTOR AngelCore::Vector<4>::GetXMVECTOR() const
{
	return DirectX::XMVectorSet(this->m_x, this->m_y, this->m_z, this->m_w);
}

float AngelCore::Vector<4>::Magnitude()
{
	return std::sqrt(std::pow(this->m_x, 2) + std::pow(this->m_y, 2) + std::pow(this->m_z, 2) + std::pow(this->m_w, 2));
}

const float AngelCore::Vector<4>::Magnitude() const
{
	return std::sqrt(std::pow(this->m_x, 2) + std::pow(this->m_y, 2) + std::pow(this->m_z, 2) + std::pow(this->m_w, 2));
}

float AngelCore::Vector<4>::Distance(const Vector &rhs)
{
	Vector AtoB;
	AtoB.m_x = this->m_x;
	AtoB.m_y = this->m_y;
	AtoB.m_z = this->m_z;
	AtoB.m_w = this->m_w;

	AtoB -= rhs;
	return AtoB.Magnitude();
}

const float AngelCore::Vector<4>::Distance(Vector const &rhs) const
{
	Vector AtoB;
	AtoB.m_x = this->m_x;
	AtoB.m_y = this->m_y;
	AtoB.m_z = this->m_z;
	AtoB.m_w = this->m_w;

	AtoB -= rhs;
	return AtoB.Magnitude();
}

float AngelCore::Vector<4>::Dot(const Vector &rhs)
{
	return (this->m_x * rhs.m_x) + (this->m_y * rhs.m_y) + (this->m_z * rhs.m_z) + (this->m_w * rhs.m_w);
}


const float AngelCore::Vector<4>::Dot(const Vector &rhs) const
{
	return (this->m_x * rhs.m_x) + (this->m_y * rhs.m_y) + (this->m_z * rhs.m_z) + (this->m_w * rhs.m_w);
}

float AngelCore::Vector<4>::Angle(const Vector &rhs)
{
	return static_cast<float>(((acosf(this->Dot(rhs) / (this->Magnitude()*rhs.Magnitude())) * 180) / PI));
}

const float AngelCore::Vector<4>::Angle(const Vector &rhs) const
{
	return static_cast<float>(((acosf(this->Dot(rhs) / (this->Magnitude()*rhs.Magnitude())) * 180) / PI));
}
#pragma endregion