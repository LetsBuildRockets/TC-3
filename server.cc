//
// async_tcp_echo_server.cc
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
#include <queue>
#include "server.h"

std::mutex stateMutex;
std::queue<std::string> commandBuffer;

std::mutex tcpSendMutex;
std::queue<std::string> tcpSendBuffer;

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
      commandBuffer.push(data_);
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

  boost::asio::ip::tcp::socket socket_;
private:
  enum { max_length = 1024 };
  char data_[max_length];
};

class server {
public:
  server(boost::asio::io_service& io_service, short port) : io_service_(io_service), acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
    new_session__  = new session(io_service_);
    acceptor_.async_accept(new_session__->socket(), boost::bind(&server::handle_accept, this, new_session__, boost::asio::placeholders::error));
  }

  void handle_accept(session* new_session, const boost::system::error_code& error) {
    if (!error) {
      new_session->start();
      new_session = new session(io_service_);
      acceptor_.async_accept(new_session->socket(), boost::bind(&server::handle_accept, this, new_session, boost::asio::placeholders::error));
      printf("New Connection!\n");
      //sockets.push_back(new_session->socket());
    } else {
      delete new_session;
    }
  }
  void send(std::string msg) {
    //for(std::vector<int>::size_type i = 0; i < sockets.size(); i++) {
      boost::asio::write(new_session__->socket(), boost::asio::buffer(msg));
    //}
  }

private:
  boost::asio::io_service& io_service_;
  boost::asio::ip::tcp::acceptor acceptor_;
  session* new_session__;
};

void runAsyncServer() {
  try {
    printf("server starting...\n");
    boost::asio::io_service io_service;
    server s(io_service, 1337);
    while(true) {
      tcpSendMutex.lock();
      if(!tcpSendBuffer.empty())
      {
        std::string msg = (char *)tcpSendBuffer.front().c_str();
        printf("data: %s", msg.c_str());
        tcpSendBuffer.pop();
        s.send(msg);
      }
      tcpSendMutex.unlock();
      io_service.poll();
      usleep(10*1000);
    }
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }
}
