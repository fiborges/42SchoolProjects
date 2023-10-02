// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

//garant that this file is included only one time
#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {

// use out of class
public:

	//alias istead of writing Account all the time can write t
	typedef Account		t;

	//  static methods in programming are like asking questions to the group of toys instead of 
	// asking a specific toy. They are useful when you want information that applies to all 
	// objects of a class, rather than to a specific object.
	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	//constructor with a initial deposit
	Account( int initial_deposit );
	//destructor for destroying the object
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;

// use only in class
private:

	//static variables are shared by all objects of the class
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	// stamp for the time and date
	static void	_displayTimestamp( void );

	// index of the account
	int				_accountIndex;
	// amount of the account
	int				_amount;
	// number of deposits
	int				_nbDeposits;
	// number of withdrawals
	int				_nbWithdrawals;

	// private constructor
	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
