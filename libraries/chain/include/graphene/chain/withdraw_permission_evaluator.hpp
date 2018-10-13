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

#include <graphene/chain/evaluator.hpp>

namespace graphene { namespace chain {

class withdraw_permission_create_evaluator : public evaluator<withdraw_permission_create_evaluator>
{
public:
   typedef withdraw_permission_create_operation operation_type;

   void_result do_evaluate( const operation_type& op );
   object_id_type do_apply( const operation_type& op );
};

class withdraw_permission_claim_evaluator : public evaluator<withdraw_permission_claim_evaluator>
{
public:
   typedef withdraw_permission_claim_operation operation_type;

   void_result do_evaluate( const operation_type& op );
   void_result do_apply( const operation_type& op );
};

class withdraw_permission_update_evaluator : public evaluator<withdraw_permission_update_evaluator>
{
public:
   typedef withdraw_permission_update_operation operation_type;

   void_result do_evaluate( const operation_type& op );
   void_result do_apply( const operation_type& op );
};

class withdraw_permission_delete_evaluator : public evaluator<withdraw_permission_delete_evaluator>
{
public:
   typedef withdraw_permission_delete_operation operation_type;

   void_result do_evaluate( const operation_type& op );
   void_result do_apply( const operation_type& op );
};

} } // graphene::chain
