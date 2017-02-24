import unittest
from test_cfg import client
import testutil
_L = logging.getLogger(__name__)

class TestRealisticRendering(unittest.TestCase):
    def test_objects(self):
        '''
        Make sure the object list is the same as expected
        '''
        response = client.request('vget /objects')
        response = response.strip() # TODO: remove this line
        self.assertTrue(validate_format(response))

        objects = response.split(' ')
        self.assertTrue(len(objects) > 0)

        print 'Number of objects %d' % len(objects)
        tasks = []
        for objname in objects:
            tasks.append(['vget /object/%s/name' % objname, objname])
            tasks.append(['vget /object/%s/color' % objname, skip])

        testutil.run_tasks(self, self.client, tasks)

if __name__ == '__main__':
    tests = [
        'test_objects',
    ]
    suite = unittest.TestSuite(map(TestRealisticRendering, tests))
    unittest.TextTestRunner(verbosity=2).run(suite)
