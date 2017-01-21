/*
 * Tokenizer.hpp
 * Copyright (C) 2013 Alfredo Pons Menargues <alfredo.pons@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <string>

class Tokenizer
{
  public:

    /**
    * Tokenizer constructor
    * \param[in] str std::string to search for the token.
    * \param[in] delimiters Delimiter token.
    */
    Tokenizer (const std::string& str, const std::string& delimiters);
    Tokenizer ();
    void set (const std::string& str, const std::string& delimiters);
    virtual ~Tokenizer() {};

    /**
    * Prepare the next token.
    * \return true If there are any pending token. False in other case.
    */
    bool next_token();
    /*! Gets the token */
    const std::string get_token() const;

  protected:

    std::size_t m_offset;
    std::string m_string;
    std::string m_token;
    std::string m_delimiters;

    bool next_token (const std::string& delimiters);
};

#endif /* TOKENIZER_H_ */
