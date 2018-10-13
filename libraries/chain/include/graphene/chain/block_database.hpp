/*
 * Copyright (c) 2015 Cryptonomex, Inc., and contributors.  All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#pragma once
#include <fstream>
#include <graphene/chain/protocol/block.hpp>

namespace graphene { namespace chain {
   class block_database 
   {
      public:
         void open( const fc::path& dbdir );
         bool is_open()const;
         void flush();
         void close();

         void store( const block_id_type& id, const signed_block& b );
         void remove( const block_id_type& id );

         bool                   contains( const block_id_type& id )const;
         block_id_type          fetch_block_id( uint32_t block_num )const;
         optional<signed_block> fetch_optional( const block_id_type& id )const;
         optional<signed_block> fetch_by_number( uint32_t block_num )const;
         optional<signed_block> last()const;
         optional<block_id_type> last_id()const;
      private:
         mutable std::fstream _blocks;
         mutable std::fstream _block_num_to_pos;
   };
} }
