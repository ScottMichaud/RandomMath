# RandomMath

#### Version 0.0.1 (WIP)

## Overview
RandomMath is a modern C++, header-only library of math algorithms. It comes bundled with a Visual Studio 2019 C++ Unit Test project to define behaviour, but it is intended to be used in **any major, latest-release compiler**. Backward compatibility will be considered if it can be implemented without too many trade-offs.

## Design Goals
- Be fast in both Debug and Release.
- Make a stable, self-referential API within a single version.
- Let the compiler (and IDE) prevent incorrect usage as much as possible.
- Fully unit tested specification.
   - Any behavior that is not unit tested is either undefined, not yet implemented, or a bug.
   - Any undefined behavior that is unit tested _**is also a bug**_ (ex: calling PositiveModulo with a negative max value).
- Simple implementation with logical effects.
   - OOP is only for managing thin containers with a tiny API. Everything else is pure functions.
   - If passing by reference, const is used to (as much as possible) guarantee read-only.
   - Only mutate a parameter if it's a simple procedure and required for performance (ex: do something to all values of a list).
   - I avoid templates although that can be discussed on a case-by-case basis.
- Retakes are inevitable. The whole project must embrace trial-and-error.
   - Some of this will be gated with versioned namespaces / separated headers / etc.
   - Even that process will be trial-and-error.

## Ways to Contribute
1. Requesting algorithms that are interesting to you via a GitHub Issue.
   - Seriously. I might have a bit of time to throw at it, and it could be useful for many people.
2. Submitting a pull request with your own algorithms.
3. Open a GitHub Issue to discuss what should (and shouldn't) be defined for certain algorithms.
   - If possible, provide unit tests to clearly demonstrate what you mean.
4. Open a GitHub Issue to discuss performance optimization and general design patterns.
5. If you're on a compiler or library (especially STL) team -- get in touch! Let's align values!
   - scott@scott-michaud.com
6. Donate!
   - [ScottCMichaud @ Paypal](https://www.paypal.me/scottcmichaud) (The account without the C is not me.)
   - I will consider a Patreon if this gets popular.

## Code of Conduct
See: [Code of Conduct](https://github.com/ScottMichaud/RandomMath/blob/release/CODE_OF_CONDUCT.md).

## License
The goal is to be as permissive as possible, so the project [is licensed under CC0 Public Domain](https://github.com/ScottMichaud/RandomMath/blob/release/LICENSE).
