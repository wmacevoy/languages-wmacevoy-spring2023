:- discontiguous(can_pay_with/1).
:- discontiguous(can_dispense/1).
:- discontiguous(has/2).
:- discontiguous(wants/2).
:- discontiguous(customer/1).

:- dynamic(has/2).
:- dynamic(wants/2).

can_pay_with(cash).
can_pay_with(credit).

can_dispense(regular).
can_dispense(premium).

customer(tom).
has(tom,cash).
has(tom,credit).
has(tom,venmo).
wants(tom,premium).

customer(jason).
has(jason,venmo).
wants(jason,regular).


dispense(CUSTOMER,PAYMENT,FUEL) :- customer(CUSTOMER),
                     has(CUSTOMER,PAYMENT),
                     can_pay_with(PAYMENT),
                     wants(CUSTOMER,FUEL),
                     can_dispense(FUEL).
