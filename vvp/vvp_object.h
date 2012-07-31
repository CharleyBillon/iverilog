#ifndef __vvp_object_H
#define __vvp_object_H
/*
 * Copyright (c) 2012 Stephen Williams (steve@icarus.com)
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

# include  <stdlib.h>
# include  <vector>

typedef class vvp_object*vvp_object_t;
class vvp_vector4_t;

class vvp_object {
    public:
      inline vvp_object() { }
      virtual ~vvp_object() =0;
};

class vvp_darray : public vvp_object {

    public:
      inline vvp_darray(size_t siz) : size_(siz) { }
      virtual ~vvp_darray();

      inline size_t get_size(void) const { return size_; }

      virtual void set_word(unsigned adr, const vvp_vector4_t&value);

      virtual void get_word(unsigned adr, vvp_vector4_t&value);

    private:
      size_t size_;
};

template <class TYPE> class vvp_darray_atom : public vvp_darray {

    public:
      inline vvp_darray_atom(size_t siz) : vvp_darray(siz), array_(siz) { }
      ~vvp_darray_atom();

      void set_word(unsigned adr, const vvp_vector4_t&value);

      void get_word(unsigned adr, vvp_vector4_t&value);

    private:
      std::vector<TYPE> array_;
};

#endif
