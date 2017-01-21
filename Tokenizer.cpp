/*
 * Tokenizer.cpp
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

#include <Tokenizer.hpp>

Tokenizer::Tokenizer (const std::string& str, const std::string& delimiters)
{
  m_offset = 0;
  m_string = str;
  m_delimiters = delimiters;
}

bool
Tokenizer::next_token()
{
  return next_token (m_delimiters);
}

Tokenizer::Tokenizer ()
{
  m_offset = 0;
  m_string = "";
  m_delimiters = "";
}

void
Tokenizer::set (const std::string& str, const std::string& delimiters)
{
  m_offset = 0;
  m_string = str;
  m_delimiters = delimiters;
}

bool
Tokenizer::next_token (const std::string& delimiters)
{
  std::size_t i = m_string.find_first_not_of (delimiters, m_offset);

  if (std::string::npos == i)
    {
      m_offset = m_string.length();
      return false;
    }

  std::size_t j = m_string.find_first_of (delimiters, i);

  if (std::string::npos == j)
    {
      m_token = m_string.substr (i);
      m_offset = m_string.length();
      return true;
    }

  m_token = m_string.substr (i, j - i);
  m_offset = j;
  return true;
}

const std::string
Tokenizer::get_token() const
{
  return m_token;
}
