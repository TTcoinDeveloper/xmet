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

#include <fc/thread/future.hpp>

#include <QObject>

class QTimer;
class QThread;
namespace fc { class thread; }
namespace graphene { namespace app { class application; } }
class BlockChain : public QObject {
   Q_OBJECT
   Q_PROPERTY(QString webUsername MEMBER webUsername CONSTANT)
   Q_PROPERTY(QString webPassword MEMBER webPassword CONSTANT)
   Q_PROPERTY(QString rpcEndpoint MEMBER rpcEndpoint CONSTANT)

   fc::thread* chainThread;
   graphene::app::application* grapheneApp;
   fc::future<void> startFuture;
   QString webUsername;
   QString webPassword;
   QString rpcEndpoint;

public:
   BlockChain();
   virtual ~BlockChain();

public Q_SLOTS:
   void start();

Q_SIGNALS:
   void started();
};
