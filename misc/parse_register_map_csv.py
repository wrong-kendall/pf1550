#!/usr/bin/python3
from absl import logging
from absl import flags
from absl import app
import csv
import collections
from string import capwords
import IPython

FLAGS = flags.FLAGS
# TODO(kendall): Change this to True
flags.DEFINE_bool('dry_run', False, 'Dry Run')
flags.DEFINE_string(
    'input_file', 'register_map-converted_combined.csv', 'File to parse.')

REGISTER_NAME_SUBSTITUTIONS = {
    'Ldo1Volt': 'Ldo1::Volt',
    'Ldo1Ctrl': 'Ldo1::Ctrl',
    'Ldo2Volt': 'Ldo2::Volt',
    'Ldo2Ctrl': 'Ldo2::Ctrl',
    'Ldo3Volt': 'Ldo3::Volt',
    'Ldo3Ctrl': 'Ldo3::Ctrl',
    'Ldo1PwrdnSeq': 'Ldo1::PwrdnSeq',
    'Ldo2PwrdnSeq': 'Ldo2::PwrdnSeq',
    'Ldo3PwrdnSeq': 'Ldo3::PwrdnSeq',
    'Sw1Volt': 'Sw1::Volt',
    'Sw1StbyVolt': 'Sw1::StbyVolt',
    'Sw1SlpVolt': 'Sw1::SlpVolt',
    'Sw1Ctrl': 'Sw1::Ctrl',
    'Sw1Ctrl1': 'Sw1::Ctrl1',
    'Sw1PwrdnSeq': 'Sw1::PwrdnSeq',
    'Sw2Volt': 'Sw2::Volt',
    'Sw2StbyVolt': 'Sw2::StbyVolt',
    'Sw2SlpVolt': 'Sw2::SlpVolt',
    'Sw2Ctrl': 'Sw2::Ctrl',
    'Sw2Ctrl1': 'Sw2::Ctrl1',
    'Sw2PwrdnSeq': 'Sw2::PwrdnSeq',
    'Sw3Volt': 'Sw3::Volt',
    'Sw3StbyVolt': 'Sw3::StbyVolt',
    'Sw3SlpVolt': 'Sw3::SlpVolt',
    'Sw3Ctrl': 'Sw3::Ctrl',
    'Sw3Ctrl1': 'Sw3::Ctrl1',
    'Sw3PwrdnSeq': 'Sw3::PwrdnSeq',
}


def generate_register_address_to_name_tests(
        register_name: str,
        register_address: str,
        original_register_name: str):

    run_test = """
    RUN_TEST(pf1550_test.test_{original_register_name}_address);
    """
    method_body = """
    static void test_{original_register_name}_address() {{
        PF1550<{register_name}> pf1550(0x08);
        TEST_ASSERT_EQUAL({register_address}, pf1550.get_register<{register_name}>().kRegisterAddress);
    }}
    """
    return ((run_test.format(original_register_name=original_register_name)),
            (method_body.format(register_address=register_address,
                                register_name=register_name,
                                original_register_name=original_register_name)))


def parse_file(input_file):
    register_addresses = collections.defaultdict(collections.Counter)
    register_names = collections.defaultdict(collections.Counter)
    reader = csv.DictReader(input_file, delimiter=';')
    tests_to_run = ['PF1550Test pf1550_test;']
    method_bodies = ['struct PF1550Test {']
    for row in reader:
        register = hex(int(row['Register Address'], 16) +
                       int(row['Register Offset'], 16))
        register_addresses[register][row['Register Name']] += 1
        register_names[row['Register Name']][register] += 1
    for address, associated_register_names in register_addresses.items():
        if len(associated_register_names.keys()) > 1:
            logging.warning(
                'Register address assigned to multiple names: %s=%s',
                address, associated_register_names)
        else:
            all_cap_register_name = list(associated_register_names.keys())[0]
            original_register_name = capwords(
                all_cap_register_name.lower().replace('_', ' ')).replace(' ', '')
            register_name = ''
            if original_register_name in REGISTER_NAME_SUBSTITUTIONS:
                new_register_name = REGISTER_NAME_SUBSTITUTIONS[original_register_name]
                logging.info('Replacing %s with %s',
                             register_name, new_register_name)
                register_name = new_register_name
            else:
                register_name = original_register_name
            print('%s = %s' % (register_name, address))
            full_register_name = '%s::kRegister' % register_name
            test_to_run, method_body = generate_register_address_to_name_tests(
                register_name, address, original_register_name)
            tests_to_run.append(test_to_run)
            method_bodies.append(method_body)
    for address, associated_register_names in register_names.items():
        if len(associated_register_names.keys()) > 1:
            logging.warning(
                'Register names assigned to multiple addresses: %s=%s',
                address, associated_register_names)
    print(''.join(method_bodies))
    print('};')
    print(''.join(tests_to_run))


def main(argv):
    del argv
    with open(FLAGS.input_file, 'r') as input_file:
        parse_file(input_file)


if __name__ == '__main__':
    app.run(main)
