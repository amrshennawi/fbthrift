#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

import typing as _typing

import enum

import thrift.py3lite.types as _fbthrift_py3lite_types
import thrift.py3lite.exceptions as _fbthrift_py3lite_exceptions


class MyEnum(enum.Enum):
    MyValue1: MyEnum = ...
    MyValue2: MyEnum = ...


class MyStruct(_fbthrift_py3lite_types.Struct):
    MyIntField: _typing.Final[int] = ...
    MyStringField: _typing.Final[str] = ...
    MyDataField: _typing.Final[MyDataItem] = ...
    myEnum: _typing.Final[MyEnum] = ...
    oneway: _typing.Final[bool] = ...
    readonly: _typing.Final[bool] = ...
    idempotent: _typing.Final[bool] = ...
    def __init__(
        self, *,
        MyIntField: _typing.Optional[int]=...,
        MyStringField: _typing.Optional[str]=...,
        MyDataField: _typing.Optional[MyDataItem]=...,
        myEnum: _typing.Optional[MyEnum]=...,
        oneway: _typing.Optional[bool]=...,
        readonly: _typing.Optional[bool]=...,
        idempotent: _typing.Optional[bool]=...
    ) -> None: ...

    def __call__(
        self, *,
        MyIntField: _typing.Optional[int]=...,
        MyStringField: _typing.Optional[str]=...,
        MyDataField: _typing.Optional[MyDataItem]=...,
        myEnum: _typing.Optional[MyEnum]=...,
        oneway: _typing.Optional[bool]=...,
        readonly: _typing.Optional[bool]=...,
        idempotent: _typing.Optional[bool]=...
    ) -> MyStruct: ...
    def __iter__(self) -> typing.Iterator[typing.Tuple[str, _typing.Union[None, int, str, MyDataItem, MyEnum, bool, bool, bool]]]: ...


class MyDataItem(_fbthrift_py3lite_types.Struct):
    def __init__(
        self,
    ) -> None: ...

    def __call__(
        self,
    ) -> MyDataItem: ...
    def __iter__(self) -> typing.Iterator[typing.Tuple[str, _typing.Union[None]]]: ...


class MyUnion(_fbthrift_py3lite_types.Union):
    myEnum: _typing.Final[MyEnum] = ...
    myStruct: _typing.Final[MyStruct] = ...
    myDataItem: _typing.Final[MyDataItem] = ...
    def __init__(
        self, *,
        myEnum: _typing.Optional[MyEnum]=...,
        myStruct: _typing.Optional[MyStruct]=...,
        myDataItem: _typing.Optional[MyDataItem]=...
    ) -> None: ...


    class Type(enum.Enum):
        EMPTY: MyUnion.Type = ...
        myEnum: MyUnion.Type = ...
        myStruct: MyUnion.Type = ...
        myDataItem: MyUnion.Type = ...

    @classmethod
    def fromValue(cls, value: _typing.Union[None, MyEnum, MyStruct, MyDataItem]) -> MyUnion: ...
    value: _typing.Final[_typing.Union[None, MyEnum, MyStruct, MyDataItem]]
    type: Type
    def get_type(self) -> Type:...
