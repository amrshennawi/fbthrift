/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.constants;

import com.facebook.swift.codec.*;
import com.google.common.collect.*;
import java.util.*;

@SwiftGenerated
public final class ModuleConstants {
    private ModuleConstants() {}

    public static final int MY_INT = 1337;

    public static final String NAME = "Mark Zuckerberg";

    public static final String MULTI_LINE_STRING = "This
is a
multi line string.
";

    public static final List<Map<String, Integer>> STATES = ImmutableList.<Map<String, Integer>>builder()
        .add(ImmutableMap.<String, Integer>builder()
        .put("San Diego", 3211000)
        .put("Sacramento", 479600)
        .put("SF", 837400)
        .build())
        .add(ImmutableMap.<String, Integer>builder()
        .put("New York", 8406000)
        .put("Albany", 98400)
        .build())
        .build();

    public static final double X = (double)1;

    public static final double Y = 1000000.0;

    public static final double Z = (double)1000000000;

    public static final double ZERO_DOUBLE_VALUE = (double)0;

    public static final double LONG_DOUBLE_VALUE = (double)2.59961000990301e-05;

    public static final test.fixtures.constants.Company MY_COMPANY = test.fixtures.constants.Company.FACEBOOK;

    public static final String FOO = "foo";

    public static final int BAR = 42;

    public static final Map<String, String> MYMAP = ImmutableMap.<String, String>builder()
        .put("keys", "values")
        .build();

    public static final test.fixtures.constants.Internship INSTAGRAM = new test.fixtures.constants.Internship.Builder().setWeeks(12).setTitle("Software Engineer").setEmployer(test.fixtures.constants.Company.INSTAGRAM).setCompensation((double)1200).setSchool("Monters University").build();

    public static final test.fixtures.constants.Internship PARTIAL_CONST = new test.fixtures.constants.Internship.Builder().setWeeks(8).setTitle("Some Job").build();

    public static final List<test.fixtures.constants.Range> K_RANGES = ImmutableList.<test.fixtures.constants.Range>builder()
        .add(new test.fixtures.constants.Range.Builder().setMin(1).setMax(2).build())
        .add(new test.fixtures.constants.Range.Builder().setMin(5).setMax(6).build())
        .build();

    public static final List<test.fixtures.constants.Internship> INTERN_LIST = ImmutableList.<test.fixtures.constants.Internship>builder()
        .add(test.fixtures.constants.Constants.INSTAGRAM)
        .add(new test.fixtures.constants.Internship.Builder().setWeeks(10).setTitle("Sales Intern").setEmployer(test.fixtures.constants.Company.FACEBOOK).setCompensation((double)1000).build())
        .build();

    public static final test.fixtures.constants.Struct1 POD_0 = new test.fixtures.constants.Struct1.Builder().build();

    public static final test.fixtures.constants.Struct1 POD_S_0 = new test.fixtures.constants.Struct1.Builder().build();

    public static final test.fixtures.constants.Struct1 POD_1 = new test.fixtures.constants.Struct1.Builder().setA(10).setB("foo").build();

    public static final test.fixtures.constants.Struct1 POD_S_1 = new test.fixtures.constants.Struct1.Builder().setA(10).setB("foo").build();

    public static final test.fixtures.constants.Struct2 POD_2 = new test.fixtures.constants.Struct2.Builder().setA(98).setB("gaz").setC(new test.fixtures.constants.Struct1.Builder().setA(12).setB("bar").build()).setD(ImmutableList.<Integer>builder()
        .add(11)
        .add(22)
        .add(33)
        .build()).build();

    public static final test.fixtures.constants.Struct2 POD_TRAILING_COMMAS = new test.fixtures.constants.Struct2.Builder().setA(98).setB("gaz").setC(new test.fixtures.constants.Struct1.Builder().setA(12).setB("bar").build()).setD(ImmutableList.<Integer>builder()
        .add(11)
        .add(22)
        .add(33)
        .build()).build();

    public static final test.fixtures.constants.Struct2 POD_S_2 = new test.fixtures.constants.Struct2.Builder().setA(98).setB("gaz").setC(new test.fixtures.constants.Struct1.Builder().setA(12).setB("bar").build()).setD(ImmutableList.<Integer>builder()
        .add(11)
        .add(22)
        .add(33)
        .build()).build();

    public static final test.fixtures.constants.Struct3 POD_3 = new test.fixtures.constants.Struct3.Builder().setA("abc").setB(456).setC(new test.fixtures.constants.Struct2.Builder().setA(888).setC(new test.fixtures.constants.Struct1.Builder().setB("gaz").build()).setD(ImmutableList.<Integer>builder()
        .add(1)
        .add(2)
        .add(3)
        .build()).build()).build();

    public static final test.fixtures.constants.Struct3 POD_S_3 = new test.fixtures.constants.Struct3.Builder().setA("abc").setB(456).setC(new test.fixtures.constants.Struct2.Builder().setA(888).setC(new test.fixtures.constants.Struct1.Builder().setB("gaz").build()).setD(ImmutableList.<Integer>builder()
        .add(1)
        .add(2)
        .add(3)
        .build()).build()).build();

    public static final test.fixtures.constants.Struct4 POD_4 = new test.fixtures.constants.Struct4.Builder().setA(1234).setB((double)0.333).setC((byte)25).build();

    public static final test.fixtures.constants.Union1 U_1_1 = test.fixtures.constants.Union1.fromI(97);

    public static final test.fixtures.constants.Union1 U_1_2 = test.fixtures.constants.Union1.fromD((double)5.6);

    public static final test.fixtures.constants.Union1 U_1_3 = test.fixtures.constants.Union1;

    public static final test.fixtures.constants.Union2 U_2_1 = test.fixtures.constants.Union2.fromI(51);

    public static final test.fixtures.constants.Union2 U_2_2 = test.fixtures.constants.Union2.fromD((double)6.7);

    public static final test.fixtures.constants.Union2 U_2_3 = test.fixtures.constants.Union2.fromS(new test.fixtures.constants.Struct1.Builder().setA(8).setB("abacabb").build());

    public static final test.fixtures.constants.Union2 U_2_4 = test.fixtures.constants.Union2.fromU(test.fixtures.constants.Union1.fromI(43));

    public static final test.fixtures.constants.Union2 U_2_5 = test.fixtures.constants.Union2.fromU(test.fixtures.constants.Union1.fromD((double)9.8));

    public static final test.fixtures.constants.Union2 U_2_6 = test.fixtures.constants.Union2.fromU(test.fixtures.constants.Union1);

    public static final String APOSTROPHE = "'";

    public static final String TRIPLE_APOSTROPHE = "'''";

    public static final String QUOTATION_MARK = "\"";

    public static final String BACKSLASH = "\\";

    public static final String ESCAPED_A = "\u0061";

    public static final Map<String, Integer> CHAR2ASCII = ImmutableMap.<String, Integer>builder()
        .put("'", 39)
        .put("\"", 34)
        .put("\\", 92)
        .put("\u0061", 97)
        .build();

    public static final List<String> ESCAPED_STRINGS = ImmutableList.<String>builder()
        .add("\u0061")
        .add("\u00ab")
        .add("\u006a")
        .add("\u00a6")
        .add("\u0061yyy")
        .add("\u00abyyy")
        .add("\u006ayyy")
        .add("\u00a6yyy")
        .add("zzz\u0061")
        .add("zzz\u00ab")
        .add("zzz\u006a")
        .add("zzz\u00a6")
        .add("zzz\u0061yyy")
        .add("zzz\u00abyyy")
        .add("zzz\u006ayyy")
        .add("zzz\u00a6yyy")
        .build();

    public static final boolean FALSE_C = false;

    public static final boolean TRUE_C = true;

    public static final byte ZERO_BYTE = (byte)0;

    public static final short ZERO16 = (short)0;

    public static final int ZERO32 = 0;

    public static final long ZERO64 = 0L;

    public static final double ZERO_DOT_ZERO = (double)0;

    public static final String EMPTY_STRING = "";

    public static final List<Integer> EMPTY_INT_LIST = ImmutableList.<Integer>builder()
        .build();

    public static final List<String> EMPTY_STRING_LIST = ImmutableList.<String>builder()
        .build();

    public static final Set<Integer> EMPTY_INT_SET = ImmutableSet.<Integer>builder()
        .build();

    public static final Set<String> EMPTY_STRING_SET = ImmutableSet.<String>builder()
        .build();

    public static final Map<Integer, Integer> EMPTY_INT_INT_MAP = ImmutableMap.<Integer, Integer>builder()
        .build();

    public static final Map<Integer, String> EMPTY_INT_STRING_MAP = ImmutableMap.<Integer, String>builder()
        .build();

    public static final Map<String, Integer> EMPTY_STRING_INT_MAP = ImmutableMap.<String, Integer>builder()
        .build();

    public static final Map<String, String> EMPTY_STRING_STRING_MAP = ImmutableMap.<String, String>builder()
        .build();
}
