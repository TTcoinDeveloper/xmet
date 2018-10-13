import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.2

import Graphene.Client 0.1

import "."

/// A component for choosing an Account from the chain
RowLayout {
   property GrapheneApplication app
   /// The text to show in the name field when it is empty
   property alias placeholderText: accountNameField.placeholderText
   /// Index into the balances Array of the balance to show beneath the name field
   property int showBalance: -1

   /// The Account object the user has selected
   property Account account
   /// A real in the range [0,1] representing the amount of control the wallet has over this account
   property real accountControlLevel: account && account.isLoaded? account.getActiveControl(app.wallet) : 0
   /// An Array of Balance objects held by account
   property var balances: account? Object.keys(account.balances).map(function(key){return account.balances[key]})
                                                                .filter(function(balance){return balance.amount > 0})
                                 : null

   /// Set the name field to have active focus
   function setFocus() {
      accountNameField.forceActiveFocus()
   }

   signal balanceClicked(var balance)

   Identicon {
      name: account && account.name == accountNameField.text? accountNameField.text : ""
      width: Scaling.cm(2)
      height: Scaling.cm(2)
      showOwnership: accountControlLevel > 0
      fullOwnership: accountControlLevel >= 1
   }
   Column {
      Layout.fillWidth: true
      TextField {
         id: accountNameField
         width: parent.width

         onEditingFinished: accountDetails.update(text)
         onTextChanged: if (account && account.name !== text) accountDetails.update("")
      }
      Text {
         id: accountDetails
         width: parent.width
         height: text? implicitHeight : 0
         onLinkActivated: if (link === "balance") balanceClicked(balances[showBalance].amountReal())

         Behavior on height { NumberAnimation{ easing.type: Easing.InOutQuad } }

         function update(name) {
            if (!name)
            {
               text = ""
               account = null
               return
            }

            account = app.model.getAccount(name)
            if (account == null) {
               text = qsTr("Error fetching account.")
            } else {
               text = Qt.binding(function() {
                  if (account == null)
                     return qsTr("Account does not exist.")
                  var text = qsTr("Account ID: %1").arg(!account.isLoaded? qsTr("Loading...")
                                                                         : account.id)
                  if (showBalance >= 0) {
                     var bal = balances[showBalance]
                     text += "<br/>" + qsTr("Balance: <a href='balance'>%1</a> %2").arg(String(bal.amountReal()))
                                                                                   .arg(bal.type.symbol)
                  }
                  return text
               })
            }
         }

         Behavior on text {
            SequentialAnimation {
               PropertyAnimation {
                  target: accountDetails
                  property: "opacity"
                  from: 1; to: 0
                  duration: 100
               }
               PropertyAction { target: accountDetails; property: "text" }
               PropertyAnimation {
                  target: accountDetails
                  property: "opacity"
                  from: 0; to: 1
                  duration: 100
               }
            }
         }
      }
   }
}
