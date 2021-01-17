# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [ {'description': 'Tank Level 2',
    'steps': [ {'inputs': [('PINA',0x02)], 'iterations': 1 }],
    'expected': [('PORTC',0x20)],
    },

     {'description': 'Tank Level 4',
    'steps': [ {'inputs': [('PINA',0x04)], 'iterations': 1 }],
    'expected': [('PORTC',0x30)],
    },

      {'description': 'Tank Level 6',
    'steps': [ {'inputs': [('PINA',0x06)], 'iterations': 1 }],
    'expected': [('PORTC',0x38)],
    },

      {'description': 'Tank Level 8',
    'steps': [ {'inputs': [('PINA',0x08)], 'iterations': 1 }],
    'expected': [('PORTC',0x3C)],
    },

     {'description': 'Tank Level 12',
    'steps': [ {'inputs': [('PINA',0x0C)], 'iterations': 1 }],
    'expected': [('PORTC',0x3E)],
    },

     {'description': 'Tank Level 15',
    'steps': [ {'inputs': [('PINA',0x0F)], 'iterations': 1 }],
    'expected': [('PORTC',0x3F)],
    },

    ]



