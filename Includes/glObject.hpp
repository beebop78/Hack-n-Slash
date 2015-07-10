/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glObject.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 17:56:58 by rcargou           #+#    #+#             */
/*   Updated: 2015/07/10 22:58:26 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBJECT_HPP
# define GLOBJECT_HPP

class glObject;
class hitbox;
class matrice;

# include "hacknslash.hpp"

class glObject {

	public :
		glObject();
		~glObject();

		void parse(std::string parse);

		enum e_bone {
			RIGHT_LEG,
			LEFT_LEG,
			RIGHT_ARM,
			LEFT_ARM,
			UNDEF,
		};

	protected :

		hitbox			_hitbox;

		size_t			indicesSize;
		size_t			verticesSize;

		float			*vertices;
		float			*indices;
		float			*textures;
		float			*texturesIndices;
		float			*normal;

		e_bone			bone;

		matrice			*modelMatrix;

		std::string		texturesPath;
};

#endif
