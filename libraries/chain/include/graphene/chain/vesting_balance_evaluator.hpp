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

class vesting_balance_create_evaluator;
class vesting_balance_withdraw_evaluator;

class vesting_balance_create_evaluator : public evaluator<vesting_balance_create_evaluator>
{
    public:
        typedef vesting_balance_create_operation operation_type;

        void_result do_evaluate( const vesting_balance_create_operation& op );
        object_id_type do_apply( const vesting_balance_create_operation& op );
};

class vesting_balance_withdraw_evaluator : public evaluator<vesting_balance_withdraw_evaluator>
{
    public:
        typedef vesting_balance_withdraw_operation operation_type;

        void_result do_evaluate( const vesting_balance_withdraw_operation& op );
        void_result do_apply( const vesting_balance_withdraw_operation& op );
};

} } // graphene::chain
