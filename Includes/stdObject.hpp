/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdObject.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 16:46:20 by rcargou           #+#    #+#             */
/*   Updated: 2015/07/10 22:49:17 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDOBJECT_HPP
# define STDOBJECT_HPP

class glObject;
class hitbox;
class stdObject;

# include "hacknslash.hpp"

class stdObject {

	public :

		stdObject (std::string path);
		~stdObject();

	enum e_index {
		TILE = 0,
		ROCK,
	};

	static void						get_object();
	static std::list<stdObject>		stdobjects;

	protected :

		hitbox					_hitbox;
		std::list<glObject>		globjects;
		e_index					index;

		void					parse(std::string path);
		stdObject(void);
};

#endif
