// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                	  //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ); // Numero de contas
	static int	getTotalAmount( void ); // Total de dinheiro
	static int	getNbDeposits( void ); // Numero de depositos
	static int	getNbWithdrawals( void ); // Numero de saques
	static void	displayAccountsInfos( void ); // Mostra informacoes de todas as contas

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit ); // Fazer Deposito
	bool	makeWithdrawal( int withdrawal ); // Fazer Saque ou levantamento
	int		checkAmount( void ) const; // Checar saldo
	void	displayStatus( void ) const; // Mostrar status


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
