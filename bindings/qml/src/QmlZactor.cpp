/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#include "QmlZactor.h"


///
//  Send a zmsg message to the actor, take ownership of the message
//  and destroy when it has been sent.                             
int QmlZactor::send (QmlZmsg *msgP) {
    return zactor_send (self, &msgP->self);
};

///
//  Receive a zmsg message from the actor. Returns NULL if the actor 
//  was interrupted before the message could be received, or if there
//  was a timeout on the actor.                                      
QmlZmsg *QmlZactor::recv () {
    QmlZmsg *retQ_ = new QmlZmsg ();
    retQ_->self = zactor_recv (self);
    return retQ_;
};

///
//  Return the actor's zsock handle. Use this when you absolutely need
//  to work with the zsock instance rather than the actor.            
QmlZsock *QmlZactor::sock () {
    QmlZsock *retQ_ = new QmlZsock ();
    retQ_->self = zactor_sock (self);
    return retQ_;
};

///
//  Change default destructor by custom function. Actor MUST be able to handle new message instead of default $TERM.
void QmlZactor::setDestructor (zactor_destructor_fn destructor) {
    zactor_set_destructor (self, destructor);
};


QObject* QmlZactor::qmlAttachedProperties(QObject* object) {
    return new QmlZactorAttached(object);
}


///
//  Probe the supplied object, and report if it looks like a zactor_t.
bool QmlZactorAttached::is (void *self) {
    return zactor_is (self);
};

///
//  Probe the supplied reference. If it looks like a zactor_t instance,
//  return the underlying libzmq actor handle; else if it looks like   
//  a libzmq actor handle, return the supplied value.                  
void *QmlZactorAttached::resolve (void *self) {
    return zactor_resolve (self);
};

///
//  Self test of this class.
void QmlZactorAttached::test (bool verbose) {
    zactor_test (verbose);
};

///
//  Create a new actor passing arbitrary arguments reference.
QmlZactor *QmlZactorAttached::construct (zactor_fn task, void *args) {
    QmlZactor *qmlSelf = new QmlZactor ();
    qmlSelf->self = zactor_new (task, args);
    return qmlSelf;
};

///
//  Destroy an actor.
void QmlZactorAttached::destruct (QmlZactor *qmlSelf) {
    zactor_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
