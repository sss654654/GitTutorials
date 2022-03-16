import React, {useContext, useState, useRef } from 'react';
import { ThemeContext } from 'styled-components/native';
import styled from 'styled-components/native';
import {Button,Image, Input} from '../components';
import { useSafeAreaInsets } from 'react-native-safe-area-context';
import { KeyboardAwareScrollView } from 'react-native-keyboard-aware-scroll-view';
import { signin } from '../firebase';
import { Alert } from 'react-native';

const Container = styled.View`
flex: 1;
justify-content: center;
align-items: center;
background-color: ${({theme}) => theme.background};
padding: 0 20px;
padding-top: ${({insets:{top}}) => top}px;
padding-bottom: ${({insets:{bottom}}) => bottom}px;
`;
const StyledText = styled.Text`
font-size: 30px;
color: #111111;
`;

const Signin = ({navigation}) => {
    const insets = useSafeAreaInsets();
    const theme = useContext(ThemeContext);

    const [email ,setEmail] = useState('');
    const [password, setPassword] = useState('');
    const refPassword = useRef(null);

    const _handleSigninBtnPress = async() => {
        try{
            const user = await signin({email,password});
            navigation.navigate('Profile', {user});
        }catch(e){
            Alert.alert("로그인 에러", e.message);
        }
        console.log('signin');
    }
    return (
        <KeyboardAwareScrollView 
        extraScrollHeight={20} 
        contentContainerStyle = {{flex:1}}>
    <Container insets = {insets}>
        <Image url=""/>
        <Input 
        label = "Email" 
        placeholder = "Email" 
        returnKeyType = "next" 
        value = {email} 
        onChangeText = {setEmail}
        onSubmitEditing = {() => refPassword.current.focus()}
        />
        <Input 
        ref = {refPassword}
        label = "Password" 
        placeholder = "Password" 
        returnKeyType = "done" 
        value = {password} 
        onChangeText = {setPassword}
        isPassword={true}
        onSubmitEditing = {_handleSigninBtnPress}
        />
        <Button title="로그인" onPress={_handleSigninBtnPress}/>
        <Button 
        title="회원가입" 
        onPress={() => navigation.navigate('Signup')}
        containerStyle= {{marginTop:0, backgroundColor:'transparent'}}
        textStyle= {{color: theme.btnTextLink, fontSize: 18 }}
         />
    </Container>
    </KeyboardAwareScrollView>
    );
};

export default Signin;