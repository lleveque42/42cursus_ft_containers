/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:08:25 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/10 12:38:30 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE
# define LEXICOGRAPHICAL_COMPARE

namespace ft {

	template<class InputIt1, class InputIt2>
		bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
			if (first1 == last1 && first2 == last2)
				return false;
			while (first1 != last1) {
				if (first2 == last2 || *first1 > *first2)
					return false;
				else if (*first1 < *first2)
					return true;
				++first1;
				++first2;
			}
			return first2 != last2;
		}
}

#endif
