/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:54:52 by ronanpoder        #+#    #+#             */
/*   Updated: 2023/02/05 15:08:54 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <cctype>
# include <cstdlib>

class Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);

		void	showPhonebook();
		void	createContact();
		void	searchContact(int id);
		void	exitPhonebook() const;
	private:
		Contact	contacts[8];
		int		contact_nb;
		void	addContact(Contact new_contact);
		void	offsetContacts();
};

#endif

