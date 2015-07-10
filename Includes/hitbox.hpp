/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 17:56:49 by rcargou           #+#    #+#             */
/*   Updated: 2015/07/11 01:54:25 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITBOX_HPP
# define HITBOX_HPP

class matrice;
class hitbox;

# include "hacknslash.hpp"

class hitbox {

	public :

		hitbox(void);
		~hitbox(void);

		matrice *collision(hitbox & elem);

		void setHitboxInd(float *vertices, float *indices);
		void setHitboxRel(float *vertices, float *relPoints);
		void setHitboxAbs(float *vertices, float *points);

	private :

		float point[6];

};

#endif
