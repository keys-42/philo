# Philosophers' Dinner Problem

## Overview

The Philosophers' Dinner problem is a classic synchronization problem, and the setting is as follows:

- **Philosophers and the Table**: 
  - One or more philosophers sit at a round table.
  - A large bowl of spaghetti is placed in the center of the table.

- **Actions**:
  - Philosophers alternate between eating, thinking, or sleeping.
  - While eating, they neither think nor sleep.
  - While thinking, they neither eat nor sleep.
  - While sleeping, they neither eat nor think.

- **Forks**:
  - There are forks on the table, with as many forks as philosophers.
  - Eating spaghetti with one fork is inconvenient. Hence, a philosopher takes both the forks to their left and right to eat.
  - After eating, philosophers put their forks back and start sleeping. Once they wake up, they begin thinking.
  - The simulation ends when a philosopher dies of starvation.

- **Rules**:
  - Every philosopher needs to eat and should never starve.
  - Philosophers don't communicate with each other.
  - Philosophers are unaware if another philosopher is on the brink of death.
  - Philosophers must strive to live!

## Mandatory Rules

- Each philosopher is represented by a separate thread.
- For multiple philosophers, there's a fork on each philosopher's left and right. If there's only one philosopher, only one fork should be on the table.
- To prevent fork duplication, each fork's state must be protected with a mutex.

## Further Reading

- [Race Condition - Wikipedia](https://en.wikipedia.org/wiki/Race_condition)
- [Deadlock - Wikipedia](https://en.wikipedia.org/wiki/Deadlock)

---

It's crucial for philosophers to ensure a harmonious dining experience and avoid the tragedy of starvation!
