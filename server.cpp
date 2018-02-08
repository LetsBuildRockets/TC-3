//
// async_tcp_echo_server.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2008 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <thread>
#include <string>
#include <mutex>
#include "server.hpp"

extern std::mutex stateMutex;
extern std::string commandBuffer;
class session {
public:
  session(boost::asio::io_service& io_service) : socket_(io_service) {

  }

  boost::asio::ip::tcp::socket& socket() {
    return socket_;
  }

  void start() {
    socket_.async_read_some(boost::asio::buffer(data_, max_length), boost::bind(&session::handle_read, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
  }

  void handle_read(const boost::system::error_code& error, size_t bytes_transferred) {
    if (!error) {
      stateMutex.lock();
      commandBuffer.append(data_);
      stateMutex.unlock();
      printf("msg: %s\n", data_);
      socket_.async_read_some(boost::asio::buffer(data_, max_length), boost::bind(&session::handle_read, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
      //boost::asio::async_write(socket_, boost::asio::buffer(data_, bytes_transferred), boost::bind(&session::handle_write, this, boost::asio::placeholders::error));
    } else {
      delete this;
    }
  }

  void handle_write(const boost::system::error_code& error) {
    if (!error) {
      //socket_.async_read_some(boost::asio::buffer(data_, max_length), boost::bind(&session::handle_read, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    } else {
      delete this;
    }
  }

private:
  boost::asio::ip::tcp::socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
};

class server {
public:
  server(boost::asio::io_service& io_service, short port) : io_service_(io_service), acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
    session* new_session = new session(io_service_);
    acceptor_.async_accept(new_session->socket(), boost::bind(&server::handle_accept, this, new_session, boost::asio::placeholders::error));
  }

  void handle_accept(session* new_session, const boost::system::error_code& error) {
    if (!error) {
      new_session->start();
      new_session = new session(io_service_);
      acceptor_.async_accept(new_session->socket(), boost::bind(&server::handle_accept, this, new_session, boost::asio::placeholders::error));
    } else {
      delete new_session;
    }
  }

private:
  boost::asio::io_service& io_service_;
  boost::asio::ip::tcp::acceptor acceptor_;
};

void runAsyncServer() {
  try {
    boost::asio::io_service io_service;

    server s(io_service, 1337);
    io_service.run();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }
}
