/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 23:18:50 by rcargou           #+#    #+#             */
/*   Updated: 2015/07/11 01:49:40 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "matrice.hpp"

# define TO_RADIAN(x) (x / 180.0f * 3.14)

matrice::matrice (void)
{
	points[0] = 1;
	points[1] = 0;
	points[2] = 0;
	points[3] = 0;
	points[4] = 0;
	points[5] = 1;
	points[6] = 0;
	points[7] = 0;
	points[8] = 0;
	points[9] = 0;
	points[10] = 1;
	points[11] = 0;
	points[12] = 0;
	points[13] = 0;
	points[14] = 0;
	points[15] = 1;
}

matrice::matrice(matrice & src)
{
	*this = src;
}

matrice::~matrice (void)
{

}

void matrice::rotateX(float x)
{
	matrice a;

	a.points[5] = cos(x);
	a.points[6] = -sin(x);
	a.points[9] = sin (x);
	a.points[10] = -cos(x);
	*this = *this * a;
}

void matrice::rotateY(float y)
{
	matrice a;

	a.points[0] = cos(y);
	a.points[2] = sin(y);
	a.points[8] = -sin(y);
	a.points[10] = cos(y);
	*this = *this * a;
}

void matrice::rotateZ(float z)
{
	matrice a;

	a.points[0] = cos(z);
	a.points[1] = -sin(z);
	a.points[4] = sin(z);
	a.points[5] = cos(z);
	*this = *this * a;
}

void matrice::rotate(float x, float y, float z)
{
	if (z)
		rotateZ(z);
	if (y)
		rotateY(y);
	if (x)
		rotateX(x);
}

void matrice::translate (float x, float y, float z)
{
	points[3] += x;
	points[7] += y;
	points[11] += z;
}

void matrice::project(float fov, float near, float far, float aspect)
{

	float *matrix;
	float x_scale;
	float y_scale;
	float frustrum;

	y_scale = (float)((1.0f / tan(TO_RADIAN(fov / 2.0f))) * aspect);
	x_scale = y_scale / aspect;
	frustrum = far - near;
	points[0] = x_scale;
	points[5] = y_scale;
	points[10] = -((far + near) / frustrum);
	points[11] = -((2 * near * far) / frustrum);
	points[14] = -1;
	points[15] = 0;
}

void matrice::rotateArround(float x, float y, float z, float px, float py, float pz)
{
	float a;
	float b;
	float c;
	float prevposx;
	float prevposy;
	float prevposz;

	prevposx = points[3];
	prevposy = points[7];
	prevposz = points[11];
	a = points[3] - px;
	b = points[7] - py;
	c = points[11] - pz;
	translate(-prevposx + a, -prevposy + b, -prevposz + c);
	rotate(x, y, z);
	translate(prevposx, prevposy, prevposz);
}

void matrice::lookAt(matrice target)
{
	target.translate(-points[3], -points[7], -points[11]);
	target.rotate(0, -asin(points[2]), 0);
	rotate(0, asin(asin(target[2])), 0);
}

matrice & matrice::operator=(matrice & src)
{
	for (int i = 0; i < 16; i++)
	{
		points[i] = src[i];
	}
}

matrice & matrice::operator*(matrice & s)
{
	(*this)[0] = (*this)[0] * s[0] + (*this)[4] * s[1] + (*this)[8] * s[2] + (*this)[12] * s[3];
	points[1] = (*this)[1] * s[0] + (*this)[5] * s[1] + (*this)[9] * s[2] + (*this)[13] * s[3];
	points[2] = (*this)[2] * s[0] + (*this)[6] * s[1] + (*this)[10] * s[2] + (*this)[14] * s[3];
	points[3] = (*this)[3] * s[0] + (*this)[7] * s[1] + (*this)[11] * s[2] + (*this)[15] * s[3];
	points[4] = (*this)[0] * s[4] + (*this)[4] * s[5] + (*this)[8] * s[6] + (*this)[12] * s[7];
	points[5] = (*this)[1] * s[4] + (*this)[5] * s[5] + (*this)[9] * s[6] + (*this)[13] * s[7];
	points[6] = (*this)[2] * s[4] + (*this)[6] * s[5] + (*this)[10] * s[6] + (*this)[14] * s[7];
	points[7] = (*this)[3] * s[4] + (*this)[7] * s[5] + (*this)[11] * s[6] + (*this)[15] * s[7];
	points[8] = (*this)[0] * s[8] + (*this)[4] * s[9] + (*this)[8] * s[10] + (*this)[12] * s[11];
	points[9] = (*this)[1] * s[8] + (*this)[5] * s[9] + (*this)[9] * s[10] + (*this)[13] * s[11];
	points[10] = (*this)[2] * s[8] + (*this)[6] * s[9] + (*this)[10] * s[10] + (*this)[14] * s[11];
	points[11] = (*this)[3] * s[8] + (*this)[7] * s[9] + (*this)[11] * s[10] + (*this)[15] * s[11];
	points[12] = (*this)[0] * s[12] + (*this)[4] * s[13] + (*this)[8] * s[14] + (*this)[12] * s[15];
	points[13] = (*this)[1] * s[12] + (*this)[5] * s[13] + (*this)[9] * s[14] + (*this)[13] * s[15];
	points[14] = (*this)[2] * s[12] + (*this)[6] * s[13] + (*this)[10] * s[14] + (*this)[14] * s[15];
	points[15] = (*this)[3] * s[12] + (*this)[7] * s[13] + (*this)[11] * s[14] + (*this)[15] * s[15];
	return (*this);
}

float & matrice::operator[](int index)
{
	return (points[index]);
}
