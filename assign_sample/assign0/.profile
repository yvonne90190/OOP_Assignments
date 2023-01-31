#
# @(#)local.profile 1.3	92/11/06 SMI
#
PATH=$HOME/bin:/opt/SUNWspro/bin:/usr/bin:/usr/local/bin:/etc:.:/usr/sbin:/sbin:/usr/ccs/bin:/opt/SUNWmfwm/bin:/usr/openwin/bin:/bin:/usr/etc:/usr/ucb:/etc:/usr/lib/nis:/opt/internet/bin:$HOME/bin
LD_LIBRARY_PATH=/usr/openwin/lib:/usr/dt/lib:/usr/ucblib:/usr/lib:/opt/SUNWguide/lib
#DISPLAY=:0
# set up the prompt:
	eval ` tset -s -Q -m ':?vt100' `
        PS1="`hostname`:\${PWD}\>";export PS1
        PS2='Next-Command\>';export PS2
# Set up the terminal:
        stty kill "^U" intr "^C" eof "^D"
        stty hupcl ixon ixoff
        #stty cs8 -istrip parenb
# Set up the search paths:
        INFORMIXDIR=/opt/informix5;export INFORMIXDIR

export LC_CTYPE=iso_8859_1
PATH=$INFORMIXDIR/bin:$PATH
export SQLEXEC=/opt/informix5/lib/sqlrm
export INFORMIXSERVER=online1_shm
TKURG=$HOME/Mail/.recv
NIS_PATH=org_dir.$:$
NIS_GROUP=admin.cs.nccu.edu.tw.
TCL_LIBRARY=/home1/teachers2/hwtsai/tcl7.4b2/library
TK_LIBRARY=/home1/teachers2/hwtsai/tk4.0b2/library
HISTFILE=$TKURG
# TCL_LIBRARY=/home1/teachers2/hwtsai/tcl7.3/lib
# TK_LIBRARY=/home1/teachers2/hwtsai/tk3.6/lib
export TCL_LIBRARY
export TK_LIBRARY
export PATH PS1 HISTORY NIS_PATH NIS_GROUP
GUIDEHOME=/opt/SUNWguide
MANPATH=/usr/openwin/man:/usr/dt/man:/usr/share/man:/usr/man
export TCL_LIBRARY
export TK_LIBRARY
EDITOR=vi
LM_LICENSE_FILE=/opt/pp/license/license.dat
export LM_LICENSE_FILE
export EDITOR
export PATH LD_LIBRARY_PATH DISPLAY MANPATH GUIDEHOME

alias ls='ls -F'
alias ll='ls -l'
