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
#include <graphene/chain/committee_member_evaluator.hpp>
#include <graphene/chain/committee_member_object.hpp>
#include <graphene/chain/database.hpp>
#include <graphene/chain/account_object.hpp>
#include <graphene/chain/protocol/fee_schedule.hpp>
#include <graphene/chain/protocol/vote.hpp>
#include <graphene/chain/transaction_evaluation_state.hpp>

#include <fc/smart_ref_impl.hpp>

namespace graphene { namespace chain {

void_result committee_member_create_evaluator::do_evaluate( const committee_member_create_operation& op )
{ try {
   FC_ASSERT(db().get(op.committee_member_account).is_lifetime_member());
   return void_result();
} FC_CAPTURE_AND_RETHROW( (op) ) }

object_id_type committee_member_create_evaluator::do_apply( const committee_member_create_operation& op )
{ try {
   vote_id_type vote_id;
   db().modify(db().get_global_properties(), [&vote_id](global_property_object& p) {
      vote_id = get_next_vote_id(p, vote_id_type::committee);
   });

   const auto& new_del_object = db().create<committee_member_object>( [&]( committee_member_object& obj ){
         obj.committee_member_account   = op.committee_member_account;
         obj.vote_id            = vote_id;
         obj.url                = op.url;
   });
   return new_del_object.id;
} FC_CAPTURE_AND_RETHROW( (op) ) }

void_result committee_member_update_evaluator::do_evaluate( const committee_member_update_operation& op )
{ try {
   FC_ASSERT(db().get(op.committee_member).committee_member_account == op.committee_member_account);
   return void_result();
} FC_CAPTURE_AND_RETHROW( (op) ) }

void_result committee_member_update_evaluator::do_apply( const committee_member_update_operation& op )
{ try {
   database& _db = db();
   _db.modify(
      _db.get(op.committee_member),
      [&]( committee_member_object& com )
      {
         if( op.new_url.valid() )
            com.url = *op.new_url;
      });
   return void_result();
} FC_CAPTURE_AND_RETHROW( (op) ) }

void_result committee_member_update_global_parameters_evaluator::do_evaluate(const committee_member_update_global_parameters_operation& o)
{ try {
   FC_ASSERT(trx_state->_is_proposed_trx);

   return void_result();
} FC_CAPTURE_AND_RETHROW( (o) ) }

void_result committee_member_update_global_parameters_evaluator::do_apply(const committee_member_update_global_parameters_operation& o)
{ try {
   db().modify(db().get_global_properties(), [&o](global_property_object& p) {
      p.pending_parameters = o.new_parameters;
   });

   return void_result();
} FC_CAPTURE_AND_RETHROW( (o) ) }

} } // graphene::chain
