/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 19:01:55 by rcargou           #+#    #+#             */
/*   Updated: 2015/07/11 01:50:23 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_HPP
# define MATRICE_HPP

#include "hacknslash.hpp"

class matrice {

	public :

		matrice (void);
		matrice (matrice & src);
		~matrice (void);

		void rotate(float x, float y, float z);
		void translate (float x, float y, float z);
		void project(float fov, float near, float far, float aspect);
		void rotateArround(float x, float y, float z,
			float px, float py, float pz);
		void lookAt(matrice target);

		matrice &  operator=(matrice & src);
		matrice & operator*(matrice & src);
		float & operator[](int index);

		void rotateX(float x);
		void rotateY(float y);
		void rotateZ(float z);
		float points[16];
};

#endif
