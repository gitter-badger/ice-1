// **********************************************************************
//
// Copyright (c) 2002
// MutableRealms, Inc.
// Huntsville, AL, USA
//
// All Rights Reserved
//
// **********************************************************************

#ifndef ICE_LOCAL_EXCEPTION_H
#define ICE_LOCAL_EXCEPTION_H

#include <Ice/Config.h>

namespace Ice
{

class ICE_API LocalException
{
public:

    LocalException(const char*, int);
    virtual ~LocalException();
    LocalException(const LocalException&);
    LocalException& operator=(const LocalException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;

protected:

    std::string debugInfo() const;

private:

    const char* file_;
    int line_;
};

ICE_API std::ostream& operator<<(std::ostream&, const LocalException&);

class ICE_API CommunicatorDestroyedException : public LocalException
{
public:    

    CommunicatorDestroyedException(const char*, int);
    CommunicatorDestroyedException(const CommunicatorDestroyedException&);
    CommunicatorDestroyedException& operator=(
	const CommunicatorDestroyedException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

class ICE_API SystemException : public LocalException
{
public:    

    SystemException(const char*, int);
    SystemException(const SystemException&);
    SystemException& operator=(const SystemException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;

protected:

    int error_;
};

class ICE_API SocketException : public SystemException
{
public:    

    SocketException(const char*, int);
    SocketException(const SocketException&);
    SocketException& operator=(const SocketException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

class ICE_API ConnectFailedException : public SocketException
{
public:    

    ConnectFailedException(const char*, int);
    ConnectFailedException(const ConnectFailedException&);
    ConnectFailedException& operator=(const ConnectFailedException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

class ICE_API ConnectionLostException : public SocketException
{
public:    

    ConnectionLostException(const char*, int);
    ConnectionLostException(const ConnectionLostException&);
    ConnectionLostException& operator=(const ConnectionLostException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

class ICE_API DNSException : public SystemException
{
public:    

    DNSException(const char*, int);
    DNSException(const DNSException&);
    DNSException& operator=(const DNSException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

class ICE_API ProtocolException : public LocalException
{
public:

    ProtocolException(const char*, int);
    ProtocolException(const ProtocolException&);
    ProtocolException& operator=(const ProtocolException&);
};

class ICE_API UnmarshalOutOfBoundsException : public ProtocolException
{
public:    
    
    UnmarshalOutOfBoundsException(const char*, int);
    UnmarshalOutOfBoundsException(const UnmarshalOutOfBoundsException&);
    UnmarshalOutOfBoundsException& operator=(
	const UnmarshalOutOfBoundsException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

class ICE_API UnsupportedProtocolException : public ProtocolException
{
public:    

    UnsupportedProtocolException(const char*, int);
    UnsupportedProtocolException(const UnsupportedProtocolException&);
    UnsupportedProtocolException& operator=(
	const UnsupportedProtocolException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

class ICE_API UnsupportedEncodingException : public ProtocolException
{
public:    

    UnsupportedEncodingException(const char*, int);
    UnsupportedEncodingException(const UnsupportedEncodingException&);
    UnsupportedEncodingException& operator=(
	const UnsupportedEncodingException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

class ICE_API InvalidMessageException : public ProtocolException
{
public:    

    InvalidMessageException(const char*, int);
    InvalidMessageException(const InvalidMessageException&);
    InvalidMessageException& operator=(const InvalidMessageException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

class ICE_API UnknownMessageException : public ProtocolException
{
public:    

    UnknownMessageException(const char*, int);
    UnknownMessageException(const UnknownMessageException&);
    UnknownMessageException& operator=(const UnknownMessageException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

class ICE_API CloseConnectionException : public ProtocolException
{
public:    

    CloseConnectionException(const char*, int);
    CloseConnectionException(const CloseConnectionException&);
    CloseConnectionException& operator=(const CloseConnectionException&);
    virtual std::string toString() const;
    virtual LocalException* clone() const;
    virtual void raise() const;
};

}

#endif
