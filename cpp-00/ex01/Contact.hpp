/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:23:20 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/12/04 12:35:33 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact{
	public:
		Contact(void);
		~Contact(void);

		void	printContact() const;
		void	printContactLine(int i) const;

		// getters
		std::string	getFirstname() const;
		std::string	getLastname() const;
		std::string	getNickname() const;
		std::string	getPhoneNb() const;
		std::string	getDarkestSecret() const;

		// setters
		void setFirstname(std::string firstname);
		void setLastname(std::string lastname);
		void setNickname(std::string nickname);
		void setPhoneNb(std::string phoneNb);
		void setDarkestSecret(std::string darkest_secret);

	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phoneNb;
		std::string	darkestSecret;

};

#endif
